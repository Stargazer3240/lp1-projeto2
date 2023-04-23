// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
 private:
  T value;
  Node* next;

 public:
  Node() { this->next = nullptr; }

  T getValue() { return value; }
  Node* getNext() { return next; }

  void setValue(T value) { this->value = value; }
  void setNext(Node* next) { this->next = next; }

  void operator=(Node* node) {
    this->value = node->value;
    this->next = node->next;
  }
};

#endif
