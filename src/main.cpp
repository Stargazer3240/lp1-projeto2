// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include <iostream>

#include "linked_list.h"
#include "music.h"
#include "playlist.h"

using std::cout;

int main() {
  List<Music> lista;
  Music macarena("Macarena", "Joseph");
  lista.push_back(&macarena);
  cout << lista.search(&macarena) << '\n';
  // lista.remove(5);
  // cout << lista.search(5) << '\n';

  return 0;
}
