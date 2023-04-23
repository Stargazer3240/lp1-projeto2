// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include <iostream>

#include "linked_list.h"
#include "music.h"
#include "playlist.h"

using std::cout;

int main() {
  List<int> lista;
  int number{5};
  int* ref{&number};
  lista.push_back(ref);
  cout << lista.search(ref) << '\n';
  // lista.remove(5);
  // cout << lista.search(5) << '\n';

  return 0;
}
