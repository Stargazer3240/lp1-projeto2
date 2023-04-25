// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
 public:
  T value;
  Node* next;

  explicit Node(T value) {
    this->value = value;
    this->next = nullptr;
  }
};

#endif
