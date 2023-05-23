// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

#include "node.h"

using std::cout;

/*!
 * @brief A class that represents a linked list.
 *
 * A linked list is a data structure made of a head and a tail, with the head
 * being the first node in the list and the tail the last one.
 * @see Node
 */
template <typename T>
class List {
 private:
  Node<T>* head; /*!< The first node in the list. */
  Node<T>* tail; /*!< The last node in the list. */
  int size;      /*!< The size of the linked list. */

 public:
  /*!
   * @brief A constructor.
   *
   * Creates an empty linked list whose head and tails are nullptrs.
   */
  List() {
    this->head = nullptr;
    this->tail = nullptr;
    size = 0;
  }

  /*!
   * @brief A getter.
   *
   * Get the size of the list.
   * @return The size of the list.
   */
  int getSize() const { return size; }

  /*!
   * @brief Gets a pointer to the corresponding node of an index, if any.
   *
   * This method uses a linear search to check if the input index can be
   * found. If so, returns a pointer to it, if not, returns a nullptr.
   * @see head; size
   * @param index the integer index of the desired node.
   * @return A pointer to the linear search result.
   */
  Node<T>* get(int index) {
    if (index < 0 || index >= size) {
      cout << "Out of index!" << '\n';
    } else if (size > 0) {
      Node<T>* iterator = head;
      for (int i{0}; i < index; ++i) {
        iterator = iterator->next;
      }
      return iterator;
    } else {
      cout << "Empty list!" << '\n';
    }
    return nullptr;
  }

  /*!
   * @brief Gets a const pointer to the corresponding node of the index, if any.
   *
   * This method uses a linear search to check if the input index can be
   * found. If so, returns a const pointer to it, if not, returns a nullptr.
   * @see head; size
   * @param index the integer index of the desired node.
   * @return A const pointer to the linear search result.
   */
  Node<T>* get(int index) const {
    if (index < 0 || index >= size) {
      cout << "Out of index!" << '\n';
    } else if (size > 0) {
      Node<T>* iterator = head;
      for (int i{0}; i < index; ++i) {
        iterator = iterator->next;
      }
      return iterator;
    } else {
      cout << "Empty list!" << '\n';
    }
    return nullptr;
  }

  /*!
   * @brief Inserts a value at the end of the linked list.
   *
   * This method creates a node using dynamic allocation and inserts it at the
   * end of the list, while also incrementing the list's size.
   * @see size; tail;
   * @param value a generic value that will be inserted at the end of the list.
   */
  void push_back(T value) {
    auto new_node = new Node<T>(value);
    if (size == 0) {
      head = tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
    ++size;
  }

  /*!
   * @brief Removes a node from the linked list.
   *
   * This method checks if there is a node at set index and removes it from the
   * list if true, releasing it from the heap, while also decreasing the list's
   * size.
   * @see head; size; get()
   * @param index the integer index of the desired node to remove.
   */
  void remove(int index) {
    if (index < 0 || index >= size) {
      cout << "Out of index!" << '\n';
    } else {
      Node<T>* node = get(index);
      if (index == 0) {
        head = head->next;
      } else {
        Node<T>* previous_node = get(index - 1);
        previous_node->next = node->next;
        if (node == tail) {
          tail = previous_node;
        }
      }
      delete node;
      --size;
    }
  }

  void clear(int index) {
    if (index < 0 || index >= size) {
      cout << "Out of index!" << '\n';
    } else {
      Node<T>* node = get(index);
      if (index == 0) {
        head = head->next;
      } else {
        Node<T>* previous_node = get(index - 1);
        previous_node->next = node->next;
        if (node == tail) {
          tail = previous_node;
        }
      }
      delete node->value;
      delete node;
      --size;
    }
  }
  /*!
   * @brief Empties a linked list.
   *
   * Removes all nodes from a set linked list.
   * @see remove()
   */
  void remove_nodes() {
    while (size != 0) {
      remove(0);
    }
  }

  void clear_nodes() {
    while (size != 0) {
      clear(0);
    }
  }

  /*!
   * @brief Prints the nodes of a linked list.
   *
   * Prints all nodes of a linked list.
   * @see get(); Node::value; Music::operator<<(); Playlist::operator<<()
   */
  void print() const {
    for (int i{0}; i < size; ++i) {
      cout << i + 1 << ". " << get(i)->value;
    }
  }
};

#endif
