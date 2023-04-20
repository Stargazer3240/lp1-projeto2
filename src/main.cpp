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
  lista.push_back(5);
  cout << lista.search(5) << '\n';
  // lista.remove(5);
  // cout << lista.search(5) << '\n';

  return 0;
}
