// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include <iostream>

#include "node.h"

using std::cout;

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
  Node<T>* tail; /*!< The last node in the list. Always points to nullptr */
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
   * @brief A destructor.
   *
   * Deletes all nodes of the linked list.
   *
   * @see empty()
   */
  ~List() { empty(); }

  /*!
   * @brief A getter.
   *
   * Get the size of the list.
   * @return The size of the list.
   */
  int getSize() const { return size; }

  /*!
   * @brief Search if there is a node at an input index.
   *
   * This method uses a linear search to check if an input index can be
   * found.
   * @param index the integer index of the desired node.
   * @return True or False as the result of the search.
   */
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

  /*!
   * @brief Gets a pointer to the corresponding node of an index, if any.
   *
   * This method uses a linear search to check if the input index can be
   * found. If so, returns a pointer to it, if not, returns a nullptr.
   * @param index the integer index of the desired node.
   * @return A pointer to the linear search result.
   */
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

  /*!
   * @brief Gets a const pointer to the corresponding node of the index, if any.
   *
   * This method uses a linear search to check if the input index can be
   * found. If so, returns a const pointer to it, if not, returns a nullptr.
   * @param index the integer index of the desired node.
   * @return A const pointer to the linear search result.
   */
  Node<T>* get(int index) const {
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
      new_node->value = value;
    }
    ++size;
  }

  /*!
   * @brief Removes a node from the linked list.
   *
   * This method checks if there is a node at set index and removes it from the
   * list if true, releasing it from the heap, while also decreasing the list's
   * size.
   * @see head; size; search(); get()
   * @param index the integer index of the desired node to remove.
   */
  void remove(int index) {
    if (index < 0 || index >= size) {
      cout << "Out of index!" << '\n';
    } else if (search(index)) {
      Node<T>* dummy = nullptr;
      if (index == 0) {
        dummy = head;
        head = head->next;
      } else {
        dummy = get(index);
        Node<T>* previous_dummy = get(index - 1);
        previous_dummy->next = dummy->next;
      }
      delete dummy;
      --size;
    }
  }

  /*!
   * @brief Empties a linked list.
   *
   * Removes all nodes from a set linked list.
   * @see remove()
   */
  void empty() {
    for (int i{0}; i < size; ++i) {
      remove(i);
    }
  }

  void print() {
    for (int i{0}; i < size; ++i) {
      cout << i + 1 << ". " << get(i)->value;
    }
  }
};

#endif
