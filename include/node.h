// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include <iostream>

using std::cout;

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
 private:
  T value;
  Node* next;

 public:
  Node(T value) : value{value}, next{nullptr} {}

  T getValue() const { return value; }
  Node* getNext() const { return next; }

  void setValue(const T& value) { this->value = value; }
  void setNext(const Node* next) { this->next = next; }

  Node operator=(const T& node) {
    this->value = node.value;
    this->next = node.next;
  }

  friend void operator<<(std::ostream& os, const T& node) {
    cout << node.value;
  }
};

#endif
