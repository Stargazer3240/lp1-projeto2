// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#ifndef NODE_H
#define NODE_H

/*!
 * @brief A class that represents a node in a linked list.
 *
 * A node is an "atomic" entity that, when chained together, creates the linked
 * list. Each node is made of a value and a pointer to the next node.
 */
template <typename T>
class Node {
 public:
  T value;    /*!< Data piece of the node. */
  Node* next; /*!< Pointer to the next node in the list. */

  /*!
   * @brief A constructor.
   *
   * Creates a node with a generic input value and points next to a nullptr.
   * @param value a generic value that represents the data that will be inserted
   * in the node.
   */
  explicit Node(T value) {
    this->value = value;
    this->next = nullptr;
  }
};

#endif
