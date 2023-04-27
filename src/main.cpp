// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "linked_list.h"
#include "music.h"
#include "playlist.h"

template <typename T>
void print(List<T>& lista) {
  for (int i{0}; i < lista.getSize(); ++i) {
    cout << lista.get(i)->value << '\n';
  }
}

int main() {
  List<int> lista;
  lista.push_back(5);
  lista.push_back(6);
  lista.push_back(10);
  print(lista);
  cout << '\n';
  lista.remove(0);
  print(lista);
  cout << '\n';
  lista.remove(1);
  print(lista);
  cout << '\n';
  lista.empty();
  lista.push_back(5);
  lista.push_back(6);
  lista.push_back(10);
  lista.remove(1);
  print(lista);

  return 0;
}
