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
  Playlist play2("Bossa Nova Night");
  Music mus1("M1", "A1");
  Music mus2("M2", "A2");
  Music mus3("M3", "A3");
  Music mus4("M4", "A4");
  Music mus5("M5", "A5");

  List<Playlist*> system;

  system.push_back(&play1);
  system.push_back(&play2);

  cout << system.get(0)->value->getName() << '\n';
  system.get(0)->value->add_music(&mus1);
  system.get(0)->value->add_music(&mus3);
  system.get(0)->value->add_music(&mus4);
  system.get(0)->value->print();
  system.get(0)->value->remove_music(1);
  cout << '\n';
  system.get(0)->value->print();

  cout << '\n' << system.get(1)->value->getName() << '\n';
  system.get(1)->value->add_music(&mus1);
  system.get(1)->value->add_music(&mus2);
  system.get(1)->value->add_music(&mus5);
  system.get(1)->value->print();
  cout << '\n';
  system.get(1)->value->remove_music(1);
  system.get(1)->value->print();

  cout << '\n' << mus1 << mus2 << mus3 << mus4 << mus5;

  return 0;
}
