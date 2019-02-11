#ifndef NODE_H
#define NODE_H

#include "stdint.h"

class Node {
public:
  Node *next;
  uint8_t data;

  Node(uint8_t _data) {
    data = _data;
    next = nullptr;
  }
};

#endif