// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "node.h"

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
class List {
 public:
  Node<T>* head;
  Node<T>* tail;
  int size;

  List() {
    auto head = new Node<T>;
    auto tail = new Node<T>;
    this->head = head;
    this->tail = tail;
    size = 0;
  }

  ~List() { empty(); }

  bool search(T value) {
    Node<T>* node = head;
    bool to_return = false;

    if (size == 1) {
      if (head->getValue() == value) {
        to_return = true;
      }
    } else if (size > 1) {
      while (node->getNext() != nullptr) {
        if (node->getValue() == value) {
          to_return = true;
        }
        node = node->getNext();
      }
    }

    return to_return;
  }

  Node<T>* find(T value) {
    Node<T>* node = head;
    while (node->getNext() != nullptr) {
      if (node->getValue() == value) {
        return node;
      }
      node = node->getNext();
    }
    return nullptr;
  }

  void push_back(T value) {
    auto new_node = new Node<T>;
    new_node->setValue(value);
    new_node->setNext(nullptr);
    tail->setNext(new_node);
    ++size;
  }

  void remove(T value) {
    Node<T>* node = find(value);
    if (!node) {
      delete *node;
    }
    --size;
  }

  void empty() {
    Node<T>* node = head;
    while (node->getNext() != nullptr) {
      delete head;
      node = node->getNext();
      head = node;
    }
  }
};

#endif
