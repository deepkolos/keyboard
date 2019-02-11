#ifndef KEYBOARD_VARS_H
#define KEYBOARD_VARS_H

#define KEYBOARD_ROWS 5
#define KEYBOARD_COLS 13
#define DEBOUNCE 5

#ifdef __DEBUG__
#define Debug(info) Serial.print(info)
#else
#define Debug(info)
#endif

#ifdef __LOG__
#define Log(info) Serial.print(info)
#else
#define Log(info)
#endif

#define SET_FOREACH(set, fn)                                                   \
  if (set.head != nullptr) {                                                   \
    Node *curr = set.head;                                                     \
    while (curr->next != nullptr) {                                            \
      fn(curr->data);                                                          \
      curr = curr->next;                                                       \
    }                                                                          \
    fn(curr->data);                                                            \
  }

int indexOf(const uint8_t list[], uint8_t len, uint8_t keycode) {
  uint8_t i;
  if (len != 0)
    for (i = 0; i < len; i++)
      if (list[i] == keycode)
        return i;
  return -1;
}

#endif
