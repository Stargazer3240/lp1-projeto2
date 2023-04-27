// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include <iostream>

using std::cout;

#include "node.h"

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
class List {
 private:
  Node<T>* head;
  Node<T>* tail;
  int size;

 public:
  List() {
    this->head = nullptr;
    this->tail = nullptr;
    size = 0;
  }

  ~List() { empty(); }

  int getSize() const { return size; }

  bool search(int index) {
    if (index < 0 || index >= size) {
      cout << "Out of index!" << '\n';
    } else if (size != 0) {
      Node<T>* iterator = head;
      for (int i{0}; i < size; ++i) {
        if (i == index) {
          return true;
        }
        iterator = iterator->next;
      }
    } else {
      cout << "Empty list!" << '\n';
    }
    return false;
  }

  Node<T>* get(int index) {
    if (index < 0 || index >= size) {
      cout << "Out of index!" << '\n';
    } else if (size != 0) {
      Node<T>* iterator = head;
      for (int i{0}; i < size; ++i) {
        if (i == index) {
          return iterator;
        }
        iterator = iterator->next;
      }
    } else {
      cout << "Empty list!" << '\n';
    }
    return nullptr;
  }

  void push_back(T value) {
    auto new_node = new Node<T>(value);
    if (size == 0) {
      head = tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
      new_node->value = value;
    }
    ++size;
  }

  void remove(int index) {
    if (index < 0 || index >= size) {
      cout << "Out of index!" << '\n';
    } else if (search(index)) {
      Node<T>* dummy = nullptr;
      if (index == 0) {
        dummy = head;
        head = head->next;
      } else if (index == size - 1) {
        dummy = get(index - 1);
        tail = dummy;
        dummy = tail->next;
      } else {
        dummy = get(index);
        Node<T>* previous_dummy = get(index - 1);
        previous_dummy->next = dummy->next;
      }
      //delete dummy->value;
      delete dummy;
      --size;
    }
  }

  void empty() {
    for (int i{0}; i < size; ++i) {
      remove(i);
    }
  }
};

#endif
