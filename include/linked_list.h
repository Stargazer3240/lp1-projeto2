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
  Node<T> head;
  Node<T> tail;

 public:
  List(Node<T> node) : head{node}, tail{node} {
    // tail.setNext(nullptr);
  }
  /*
    ~List() {
      Node<T> it_node(0);
      it_node.setNext(head);
      while (it_node.getNext() != nullptr) {
        erase_after(it_node);
      }
    }
  */
  Node<T> getHead() const { return head; }
  Node<T> getTail() const { return tail; }

  void setHead(Node<T>& head) { this->head = head; }
  void setTail(Node<T>& tail) { this->tail = tail; }

  void insert_after(const T& value, const Node<T>& insert_node) {
    Node<T> new_node = new Node<T>;
    new_node.setValue(value);
    new_node.setNext(insert_node.getNext());
    insert_node.setNext(new_node);
  }

  void erase_after(const Node<T>& erase_node) {
    Node<T> temp_next{getNext(erase_node.getNext())};
    delete erase_node.getNext();
    erase_node.setNext(temp_next.getNext());
  }

  bool search(T value) {
    Node<T> it_node = getHead();
    while (it_node.getNext() != nullptr) {
      if (it_node.getValue() == value) return 1;
      cout << (it_node.getValue());
      it_node = it_node.getNext();
    }

    return 0;
  }
};

#endif
