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

  // Playlist and Music test.
  List<Playlist*> system;
  interface();
  /*  
  Playlist play1("As 100 Melhores do Samba");
  Playlist play2("Alternative Metal");
  Music mus1("O mundo é um moinho", "Cartola");
  Music mus2("Saudosa Maloca", "Adoniran Barbosa");
  Music mus3("Toxicity", "System of a Down");
  Music mus4("Aerials", "System of a Down");
  Music mus5("Dead Memories", "Slipknot");


  system.push_back(&play1);
  system.push_back(&play2);

  cout << system.get(0)->value->getName() << '\n';
  system.get(0)->value->add_music(&mus1);
  system.get(0)->value->add_music(&mus4);
  system.get(0)->value->add_music(&mus2);
  system.get(0)->value->print();
  for(int i{0}; i < 4; ++i){
    cout << system.get(0)->value->next_music() << '\n';
  }

  system.get(0)->value->remove_music(1);
  cout << '\n';
  system.get(0)->value->print();

  cout << '\n' << system.get(1)->value->getName() << '\n';
  system.get(1)->value->add_music(&mus3);
  system.get(1)->value->add_music(&mus4);
  system.get(1)->value->add_music(&mus5);
  system.get(1)->value->add_music(&mus2);
  system.get(1)->value->print();
  cout << '\n';
  system.get(1)->value->remove_music(3);
  system.get(1)->value->print();

  cout << '\n' << mus1 << '\n' << mus2 << '\n' << mus3 << '\n' << mus4 << '\n' << mus5 << '\n';
*/  

  while(true){
    cout << "IMDJ - Music Manager\n1 - Manage Musics\n2 - Manage Playlists\n" 
        "Manage Musics in a Playlist\n0 - Exit\nChoose one option: ";
    int index;
    cin >> index;

    switch(index) {
      case 1:
        system.get(0); 
        break;
      case 2:

        break;
      case 3:
        
        break;
      case 0:
        return;
      default: 
        cout << "Invalid number!\n";
        break;
    }
  }

  return 0;
}
