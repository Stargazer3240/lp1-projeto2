// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "node.h"

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T> class List {
private:
  Node<T> head;
  Node<T> tail;

public:
  List(Node<T> h) : head{h} { h.setNext(nullptr); }
  ~List() {
    Node<T> n(0, head);
    while (n.getNext() != nullptr) {
      erase_after(n);
    }
  }

  const Node<T> getHead() { return head; }
  const Node<T> getTail() { return tail; }

  void setHead(Node<T> &h) { head = h; }
  void setTail(Node<T> &t) { tail = t; }

  void insert_after(const T &v, const Node<T> &n) {
    Node<T> new_node = new Node<T>;
    new_node.setValue(v);
    new_node.setNext(n.getNext());
    n.setNext(new_node);
  }

  void erase_after(const Node<T> &n) {
    Node<T> temp_next{getNext(n.getNext())};
    delete n.getNext();
    n.setNext(temp_next.getNext());
  }
};

#endif
