// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "playlist.h"

// Linked list test.
/*
template <typename T>
void print(List<T>& lista) {
  for (int i{0}; i < lista.getSize(); ++i) {
    cout << lista.get(i)->value << '\n';
  }
}
*/

int main() {
  // Linked list test.
  /*
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
  */

  Playlist play1("As 100 Melhores do Samba");
  Music mus1("M1", "A1");
  List<Playlist*> lista;
  lista.push_back(&play1);
  cout << lista.get(0)->value->getName() << '\n';
  lista.get(0)->value->add_music(&mus1);
  lista.get(0)->value->print();
  lista.get(0)->value->remove_music(0);
  lista.get(0)->value->print();
  cout << mus1;

  return 0;
}
