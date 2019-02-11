// #define __LOG__
// #define __DEBUG__
#include "keyboard.stm32.h"

Keyboard keyboard;

void setup() { keyboard.init(); }

void loop() { keyboard.scan(); }