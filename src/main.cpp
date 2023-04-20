// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include <iostream>

#include "linked_list.h"
#include "music.h"
#include "playlist.h"

using std::cout;

int main() {
  /*
  Node<int> hello(5, nullptr);
  Node<int>* ptr_hello{&hello};
  Node<int> hi(10, ptr_hello);

  cout << hello.getValue() << " " << hello.getNext() << '\n';
  cout << hi.getValue() << " " << hi.getNext() << '\n';
*/
  Node<int> node1(5);

  List<Node<int>> lista(node1);
  lista.search(5);

  return 0;
}
