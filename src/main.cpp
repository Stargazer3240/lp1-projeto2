// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "linked_list.h"
#include "music.h"
#include "playlist.h"

int main() {
  List<int> lista;
  lista.push_back(5);
  cout << lista.get(0)->value << '\n';

  return 0;
}
