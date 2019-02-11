#ifndef KEYBOARD_BASE_H
#define KEYBOARD_BASE_H

#include "../struct/set.h"
#include "../struct/stack.h"
#include "Arduino.h"
#include "keycode.h"
#include "keymap.composite.h"
#include "keymap.h"
#include "stdint.h"
#include "vars.h"

extern uint8_t compositeKeyLen;
extern composite_key_t compositeKeymap[];

class KeyboardBase {
public:
  uint8_t *rows;
  uint8_t *cols;

  uint8_t debounce = 0;
  uint8_t keyPressedNum = 0;
  uint8_t keyReleasedNum = 0;

  uint16_t currColState[KEYBOARD_ROWS];
  uint16_t prevColState[KEYBOARD_ROWS];
  uint16_t tempColState[KEYBOARD_ROWS];

  Stack keyPressStack;
  Stack keyReleaseStack;
  Set recoverKeySet;
  Set pressTriggerKeySet;
  Set blockedPressKeySet;

  ~KeyboardBase(){};
  void init();
  void setPinMode();
  void scan();
  void testKeyEvent();
  void emitKeyEvent(uint8_t, uint8_t, bool);
  void sendKey(uint8_t, bool);

  // scan
  uint16_t getColState();
  uint8_t getKeyCodeFromPos(uint8_t, uint8_t);

  // composite
  void removeKeyFromBlockedSet(uint8_t keycode);
  void triggerCompositeKey(uint8_t keycode, bool pressed);
  bool checkInAllowInsertKeyList(composite_key_t *cpsKey, uint8_t keycode);

  virtual void pressKey(uint8_t){};
  virtual void releaseKey(uint8_t){};
};

void KeyboardBase::init() {
  setPinMode();
  initCompostieKeymap();

#if defined(__DEBUG__) || defined(__LOG__)
  Serial.begin(115200);
#endif
}

void KeyboardBase::setPinMode() {
  uint8_t row, col, keycode;
  for (row = 0; row < KEYBOARD_ROWS; row++) {
    currColState[row] = 0;
    prevColState[row] = 0;
    tempColState[row] = 0;
    pinMode(rows[row], OUTPUT);
    digitalWrite(rows[row], HIGH);
  }

  for (col = 0; col < KEYBOARD_COLS; col++) {
    pinMode(cols[col], INPUT_PULLUP);
  }
}

void KeyboardBase::scan() {
  uint8_t row;
  uint16_t colState;

  for (row = 0; row < KEYBOARD_ROWS; row++) {
    digitalWrite(rows[row], LOW);
    colState = getColState();
    digitalWrite(rows[row], HIGH);

    if (tempColState[row] != colState) {
      // 检测到变化, 开始防抖, 延迟currColState生效
      tempColState[row] = colState;
      debounce = DEBOUNCE;
      Debug("col changed\n");
    }
  }

  if (debounce) {
    if (--debounce) {
      Debug("debounce remain: ");
      Debug(debounce);
      Debug('\n');
      delay(1UL);
    } else {
      Debug("end debounce\n");
      for (row = 0; row < KEYBOARD_ROWS; row++) {
        currColState[row] = tempColState[row];
      }
      testKeyEvent();
    }
  }
}

void KeyboardBase::testKeyEvent() {
  uint8_t row, col;
  uint16_t changedCol;
  for (row = 0; row < KEYBOARD_ROWS; row++) {
    if (currColState[row] != prevColState[row]) {
      // 触发事件
      // 提取出该行哪列变化
      // 变化就是不同通过异或运算来取得
      changedCol = currColState[row] ^ prevColState[row];

      for (col = 0; col < KEYBOARD_COLS; col++) {
        // 当包含了当前列
        if (changedCol & 1UL << col) {
          // 触发事件, 参数: row, col, press/release
          bool pressed = currColState[row] & 1UL << col;
          emitKeyEvent(row, col, pressed);

          prevColState[row] = currColState[row];
        }
      }
    }
  }
}

void KeyboardBase::emitKeyEvent(uint8_t row, uint8_t col, bool pressed) {
  // 获取物理键盘对应按钮的键码
  uint8_t keycode = getKeyCodeFromPos(row, col);
  if (pressed) {
    keyPressStack.push(keycode);
    keyPressedNum++;
  } else {
    keyReleaseStack.push(keycode);
    keyPressedNum++;
  }

  triggerCompositeKey(keycode, pressed);

  // 当keyPressedNum 和 keyPressedNum相等的时候就清0
  if (keyPressedNum == keyPressedNum) {
    keyPressedNum = keyPressedNum = 0;
    keyPressStack.empty();
    keyReleaseStack.empty();
  }

  Log("key event: ");
  Log(row);
  Log(',');
  Log(col);
  Log(',');
  Log(pressed ? "down" : "up");
  Log('\n');
}

uint8_t KeyboardBase::getKeyCodeFromPos(uint8_t row, uint8_t col) {
  return keymap[row][col];
}

uint16_t KeyboardBase::getColState() {
  uint8_t col;
  uint8_t val;
  uint16_t _state = 0;

#ifdef __DEBUG__
  // Debug("cols: ");
  // for (col = 0; col < KEYBOARD_COLS; col++) {
  //   Debug(cols[col]);
  //   Debug(' ');
  // }
  // Debug('\n');
  delay(200UL);
#endif

  Debug("col state bit: ");
  for (col = 0; col < KEYBOARD_COLS; col++) {
    val = digitalRead(cols[col]);
    _state |= ((uint16_t)val ? 0 : 1) << col;
    Debug(digitalRead(cols[col]));
  }
  Debug('\n');

  Debug(_state);
  Debug('\n');

  return _state;
}

void KeyboardBase::sendKey(uint8_t keycode, bool pressed) {
  pressed ? this->pressKey(keycode) : this->releaseKey(keycode);
}

// TODO: 想办法挪到单独文件, base太大了
bool KeyboardBase::checkInAllowInsertKeyList(composite_key_t *cpsKey,
                                             uint8_t keycode) {
  uint8_t i;
  if (cpsKey->keyAllowInsertLen != 0)
    for (i = 0; i < cpsKey->keyAllowInsertLen; i++)
      if (cpsKey->keyAllowInsert[i] == keycode)
        return true;
  return false;
}

void KeyboardBase::removeKeyFromBlockedSet(uint8_t keycode) {
  blockedPressKeySet.remove(keycode);
}

void KeyboardBase::triggerCompositeKey(uint8_t keycode, bool pressed) {
  uint8_t i, j;
  int scanKeyIndex;
  bool block = false;
  bool isShortRecoverKey = false;
  bool hasTrigger = false;

  composite_key_t *cpsKey;
  for (i = 0; i < compositeKeyLen; i++) {
    cpsKey = &compositeKeymap[i];

    if (pressed) {
      Debug("press: ");
      if (cpsKey->scanKeys[cpsKey->matched] == keycode) {
        Debug("scan key");

        cpsKey->matched++;
        // 阻塞该默认
        if (cpsKey->matched == 1 && cpsKey->mode == 1 &&
            cpsKey->unmatched == 0) {
          // 取消阻塞
        } else if (!(cpsKey->matched == 1 && cpsKey->unmatched != 0)) {
          block = true;
          blockedPressKeySet.add(keycode);
        }
        // 判断时候打到触发条件
        if (cpsKey->matched == cpsKey->scanKeyLen && cpsKey->unmatched == 0) {
          // 继续打补丁
          if (cpsKey->mode == 1)
            releaseKey(cpsKey->scanKeys[0]);

          // 触发组合键, 一次性按下所有的按键
          for (j = 0; j < cpsKey->triggerKeyLen; j++)
            if (pressTriggerKeySet.add(cpsKey->triggerKeys[j]))
              sendKey(cpsKey->triggerKeys[j], pressed);

          if (cpsKey->mode == 1) {
            pressKey(cpsKey->scanKeys[0]);
            if (keyPressedNum <= cpsKey->scanKeyLen) {
              releaseKey(cpsKey->scanKeys[0]);
              pressKey(cpsKey->scanKeys[0]);
            }
          }

          cpsKey->hasTriggered = true;
          hasTrigger = true;

#ifdef __DEBUG__
          Debug(" and triggered");
          if (pressTriggerKeySet.head != nullptr) {
            Node *curr = pressTriggerKeySet.head;
            while (curr->next != nullptr) {
              Debug(curr->data);
              Debug(' ');
              curr = curr->next;
            }
            Debug(curr->data);
          }
#endif
        }
      }

      // 非scanKey 和 insertKey
      else if (!checkInAllowInsertKeyList(cpsKey, keycode)) {
        Debug("not insert key");

        cpsKey->unmatched++;
        // 现在组合键处于未触发状态, 则释放被阻塞的按钮, 会重复触发,
        // 不该在这里触发
        if (cpsKey->matched < cpsKey->scanKeyLen && cpsKey->matched > 0)
          for (j = 0; j < cpsKey->matched; j++) {
            // 把已经match, 那些被阻塞的, 取消阻塞
            recoverKeySet.add(cpsKey->scanKeys[j]);

#ifdef __DEBUG__
            Debug(" add to recover set");
            if (cpsKey->scanKeys[j] == KC_CAPS)
              Debug(" error -----------------------------");

            if (keyPressStack.head != nullptr) {
              Node *curr = keyPressStack.head;
              while (curr->next != nullptr) {
                Debug(curr->data);
                Debug(' ');
                curr = curr->next;
              }
              Debug(curr->data);
            }
#endif
          }
      }
      Debug('\n');
    } else // release
    {
      // 检测是否属于组合键的扫描键

      Debug("release: ");
      scanKeyIndex = indexOf(cpsKey->scanKeys, cpsKey->scanKeyLen, keycode);
      if (scanKeyIndex != -1) {
        if (cpsKey->scanKeys[cpsKey->matched] != keycode &&
            cpsKey->unmatched != 0 &&
            !checkInAllowInsertKeyList(cpsKey, keycode))
          cpsKey->unmatched--;

        if (cpsKey->matched != 0)
          cpsKey->matched--;

        Debug("scan key");

        uint8_t firstKeyPress;
        keyPressStack.item(0, &firstKeyPress);

#ifdef __DEBUG__
        Debug(" keyPressStack: ");
        if (keyPressStack.head != nullptr) {
          Node *curr = keyPressStack.head;
          while (curr->next != nullptr) {
            Debug(curr->data);
            Debug(' ');
            curr = curr->next;
          }
          Debug(curr->data);
        }
#endif

        // 当已经触发过的时候
        if (cpsKey->hasTriggered) {
          if (!(cpsKey->mode == 1 && keycode == cpsKey->scanKeys[0])) {
            block = true;
            blockedPressKeySet.remove(keycode);
          }

          Debug(" and trigger key");

          // 慢释放
          j = scanKeyIndex > cpsKey->triggerKeyLen - 1
                  ? cpsKey->triggerKeyLen - 1
                  : scanKeyIndex;

          for (; j < cpsKey->triggerKeyLen; j++)
            if (pressTriggerKeySet.remove(cpsKey->triggerKeys[j]))
              sendKey(cpsKey->triggerKeys[j], false);

          if (cpsKey->matched == 0) {
            cpsKey->hasTriggered = false;
            cpsKey->unmatched = 0;
            recoverKeySet.empty();
            if (cpsKey->mode == 1)
              block = false;

#ifdef __DEBUG__
            Debug(" all");
            if (pressTriggerKeySet.head != nullptr) {
              Node *curr = pressTriggerKeySet.head;
              while (curr->next != nullptr) {
                Debug(curr->data);
                Debug(' ');
                curr = curr->next;
              }
              Debug(curr->data);
            }
#endif
          }
        }

        // 未触发的时候释放了中间状态
        // 仅仅触发了一个的时候
        else if ((keyPressedNum == 1 && cpsKey->scanKeys[0] == keycode &&
                  cpsKey->mode != 1) ||
                 (
                     // 这就是定制了, 非配置
                     (keycode == KC_HOME || keycode == KC_END) &&
                     firstKeyPress == KC_LSFT)) {
          isShortRecoverKey = true;

          Debug(" short recover");
        }
      }

      // 非 scan key 和非 insert key
      else if (!checkInAllowInsertKeyList(cpsKey, keycode)) {
        if (cpsKey->unmatched != 0)
          cpsKey->unmatched--;

        Debug("not insert key");
        // 如果减去之后会恢复match的阻塞状态
        if (cpsKey->unmatched == 0 && cpsKey->matched != 0 && cpsKey->mode != 1)
          for (j = 0; j < cpsKey->matched; j++)
            if (blockedPressKeySet.add(cpsKey->scanKeys[j]))
              releaseKey(cpsKey->scanKeys[j]);
      }

      Debug('\n');
    }
  }

  Debug("---------------------------------\n");

  if (!hasTrigger && pressed) {
    // recoverKeySet.foreach (pressKey);
    // recoverKeySet.foreach (removeKeyFromBlockedSet);

#ifdef __DEBUG__
    Debug("recover press: ");
    if (recoverKeySet.head != nullptr) {
      Node *curr = recoverKeySet.head;
      while (curr->next != nullptr) {
        pressKey(curr->data);
        removeKeyFromBlockedSet(curr->data);
        Debug(curr->data);
        Debug(' ');
        curr = curr->next;
      }
      Debug(curr->data);
      pressKey(curr->data);
      removeKeyFromBlockedSet(curr->data);
    }
    Debug('\n');
#endif

    recoverKeySet.empty();
  }

  if (!block) {
    sendKey(keycode, pressed);
  }

  if (isShortRecoverKey) {
    sendKey(keycode, true);
    delay(20);
    sendKey(keycode, false);
  }
}

#endif