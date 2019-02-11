#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Arduino.h"
#include "USBComposite.h"
#include "keyboard/base.h"
#include "keyboard/vars.h"
#include "stdint.h"

class Keyboard : public KeyboardBase {
private:
  USBHID hid;
  uint8_t _rows[KEYBOARD_ROWS] = {PB12, PB13, PB14, PB5, PB6};
  uint8_t _cols[KEYBOARD_COLS] = {PB7, PB8, PB9, PA0, PA1, PA2, PA3,
                                  PA4, PA5, PA6, PA7, PB0, PB1};

public:
  HIDKeyboard *key;
  HIDConsumer *consumer;

  Keyboard();
  ~Keyboard(){};
  void init();
  void _pressKey(uint8_t);
  void _releaseKey(uint8_t);

  void pressKey(uint8_t) override;
  void releaseKey(uint8_t) override;
};

Keyboard::Keyboard() {
  rows = _rows;
  cols = _cols;

  key = new HIDKeyboard(hid, 0);
  consumer = new HIDConsumer(hid);
}

void Keyboard::init() {
  hid.begin(HID_BOOT_KEYBOARD);
  key->begin();
  key->releaseAll();

  KeyboardBase::init();
}

void Keyboard::pressKey(uint8_t keycode) {
  uint16_t _code;
  switch (keycode) {
  case KC_A ... KC_EXSEL:
  case KC_LCTRL ... KC_RGUI:
    _pressKey(keycode);
    break;
  case KC_SYSTEM_POWER ... KC_SYSTEM_WAKE:
    _code = KEYCODE2SYSTEM(keycode);
    consumer->press(_code);
    break;
  case KC_AUDIO_MUTE ... KC_BRIGHTNESS_DOWN:
    _code = KEYCODE2CONSUMER(keycode);
    consumer->press(_code);
    break;
  case KC_MS_UP ... KC_MS_ACCEL2:
    _pressKey(keycode);
    break;
  case KC_TRNS:
    break;
  case KC_BOOTLOADER:
    break;
  default:
    break;
  }
}

void Keyboard::releaseKey(uint8_t keycode) {
  uint16_t _code;
  switch (keycode) {
  case KC_A ... KC_EXSEL:
  case KC_LCTRL ... KC_RGUI:
    _releaseKey(keycode);
    break;
  case KC_SYSTEM_POWER ... KC_SYSTEM_WAKE:
    // _code = KEYCODE2SYSTEM(keycode);
    // break;
  case KC_AUDIO_MUTE ... KC_BRIGHTNESS_DOWN:
    // _code = KEYCODE2CONSUMER(keycode);
    consumer->release();
    break;
  case KC_MS_UP ... KC_MS_ACCEL2:
    _releaseKey(keycode);
    break;
  case KC_TRNS:
    break;
  case KC_BOOTLOADER:
    break;
  default:
    break;
  }
}

void Keyboard::_pressKey(uint8_t k) {
  uint8_t i;
  if (k >= KC_LCTRL && k <= KC_RGUI) {
    key->keyReport.modifiers |= (1 << (k - 0xE0));
  }
  // Add k to the key report only if it's not already present
  // and if there is an empty slot.
  else if (key->keyReport.keys[0] != k && key->keyReport.keys[1] != k &&
           key->keyReport.keys[2] != k && key->keyReport.keys[3] != k &&
           key->keyReport.keys[4] != k && key->keyReport.keys[5] != k) {

    for (i = 0; i < 6; i++) {
      if (key->keyReport.keys[i] == 0x00) {
        key->keyReport.keys[i] = k;
        break;
      }
    }
    if (i == 6) {
      return;
    }
  }

  key->sendReport();
}

void Keyboard::_releaseKey(uint8_t k) {
  if (k >= KC_LCTRL && k <= KC_RGUI) {
    key->keyReport.modifiers &= ~(1 << (k - 0xE0));
  } else {
    for (unsigned i = 0; i < HID_KEYBOARD_ROLLOVER; i++) {
      if (key->keyReport.keys[i] == k) {
        key->keyReport.keys[i] = 0;
        break;
      }
    }
  }

  key->sendReport();
}

#endif