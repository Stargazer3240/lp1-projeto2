// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <initializer_list>
#include <iostream>

#include "node.h"

using std::cout, std::initializer_list;

/*!
 * @brief A class that represents a linked list.
 *
 * A linked list is a data structure made of a head and a tail, with the head
 * being the first node in the list and the tail the last one. The tail's next
 * always points to nullptr.
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
   * @brief A copy constructor.
   *
   * Initialize a linked list as a copy of another one.
   */
  List(List<T>& list) {
    this->head = list.head;
    this->tail = list.tail;
    size = list.size;
  }

  /*!
   * @brief A getter.
   *
   * Get the size of the list.
   * @return The size of the list.
   */
  int getSize() const { return size; }

  /*!
   * @brief Check if a certain element is inside a list.
   *
   * This method uses a linear search to check if the desired element can be
   * found.
   * @see head; size
   * @param element the desired element to search.
   * @return True if the element can be found, false if otherwise.
   */
  bool search(T element) {
    Node<T>* iterator = head;
    for (int i{0}; i < size; ++i) {
      if (iterator->value == element) {
        return true;
      }
      iterator = iterator->next;
    }
    return false;
  }

  /*!
   * @brief Find the index of a certain element, if it is in the list.
   *
   * This method uses a linear search to find the index of the desired element.
   * @see head; size
   * @param element the desired element to find.
   * @return The position of the element if it is in the list, -1 if it can't be
   * found.
   */
  int find(T element) {
    Node<T>* iterator = head;
    for (int i{0}; i < size; ++i) {
      if (iterator->value == element) {
        return i;
      }
      iterator = iterator->next;
    }

    return -1;
  }

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
   * @see head; tail; size
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
   * @brief Inserts another linked list at the end of the current list.
   *
   * This method appends a linked list to the current one, while preserving
   * the appended list.
   * @see head; tail; size
   * @param list a second linked list you want to append to the current one.
   */
  void add(List<T>& list) {
    for (int i{0}; i < list.getSize(); ++i) {
      this->push_back(list[i]);
    }
  }

  /*!
   * @brief Removes a node from the linked list.
   *
   * This method checks if there is a node at set index and removes it from the
   * list if true, deleting it from the heap, while also decreasing the list's
   * size.
   * @see head; tail; size; get();
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

  /*!
   * @brief Removes multiple elements from the linked list
   *
   * This method receives a list of possible elements to remove and proceeds
   * to remove the ones that can be found in the linked list.
   * @see search(); find(); remove()
   * @param list a list of elements that you want to remove.
   */
  void remove(initializer_list<T> list) {
    for (T element : list) {
      if (search(element)) {
        remove(find(element));
      }
    }
  }

  /*!
   * @brief Removes a node from the linked list.
   *
   * This method checks if there is a node at set index and removes it from the
   * list if true, deleting it from the heap, while also decreasing the list's
   * size and deleting the node's value.
   * @see head; tail; size; get(); Node::value
   * @param index the integer index of the desired node to remove.
   */
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
   * @brief Removes multiple elements from the linked list
   *
   * This method receives a list of possible elements to remove and proceeds
   * to remove the ones that can be found in the linked list, while also
   * deleting their value from the heap.
   * @see search(); find(); remove()
   * @param list a list of elements that you want to remove.
   */
  void clear(initializer_list<T> list) {
    for (T element : list) {
      if (search(element)) {
        clear(find(element));
      }
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

  /*!
   * @brief Empties a linked list.
   *
   * Removes all nodes and its values from a set linked list.
   * @see clear()
   */
  void clear_nodes() {
    while (size != 0) {
      clear(0);
    }
  }

  /*!
   * @brief Prints the nodes of a linked list.
   *
   * Prints all nodes of a linked list.
   * @see get(); Node::value;
   */
  void print() const {
    for (int i{0}; i < size; ++i) {
      cout << i + 1 << ". " << get(i)->value << '\n';
    }
  }

  List<T> operator+(List<T>& list_b) {
    List<T> list_a(*this);
    list_a.add(list_b);
    return list_a;
  }

  void operator>>(Node<T>* node) {
    if (this->getSize() == 0) {
      node = nullptr;
    } else {
      node->value = (*this)[this->size - 1];
      this->remove(this->size - 1);
    }
  }

  void operator<<(Node<T>* node) {
    if (node != nullptr) {
      this->push_back(node->value);
    }
  }

  T operator[](int index) { return get(index)->value; }

  T operator[](int index) const { return get(index)->value; }
};

#endif
