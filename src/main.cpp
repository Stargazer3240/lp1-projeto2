// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "playlist.h"

using std::cin, std::getline;

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
  /*  
  List<Playlist*> system;

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


  List<Playlist*> playlists;
  List<Music*> musics;

  // Test condition of each while.
  bool loop0{true};
  bool loop1{true};
  bool loop2{true};

  // Switch index for each loop.
  int index0{0};
  int index1{0};
  int index2{0};

  string title{""};
  string artist{""};

  // User Interface
  while(loop0){
    cout << "IMDJ - Main Menu\n1 - Manage Musics\n2 - Manage Playlists\n" 
        "3 - Manage Musics in a Playlist\n0 - Exit\nChoose an option: ";
    cin >> index0;

    switch(index0) {
      case 1:
        loop1 = true;
        while(loop1){
          cout << "IMDJ - Manage Musics Menu\n1 - Register Music\n"
            "2 - Remove Music\n3 - List Musics\n0 - Return\n"
            "Choose an option: ";
          cin >> index1;

          switch(index1){
            case 1:
              cout << "What is the title of the Music?\n";
              getline(cin, title);
              cout << "What is the artist of the MUsic?\n";
              getline(cin, artist);
              musics.push_back(); 
              break;
            case 2:
              break;
            case 3:
              break;
            case 0:
              loop1 = false;
              break;
            default:
              cout << "Invalid number!\n";
              break;
          }
        }
      case 2:
        loop2 = true; 
        while(loop2){
          cout << "IMDJ - Manage Playlists Menu\n1 - Create Playlist\n"
            "2 - Delete Playlist\n3 - List Playlists\n4 - Add Music to a Playlist"
            "\n5 - Remove Music from a Playlist\n6 - Move Music from a Playlist"
            "\n7 - Show next Music to play in a Playlist\n0 - Return";
          cin >> index2;

          switch(index2){
            case 1:
              break;
            case 2:
              break;
            case 3:
              break;
            case 4:
              break;
            case 5:
              break;
            case 0:
              loop2 = false;
              break;
            default:
              cout << "Invalid number!\n";
              break;
          }
        }
        break;
      case 0:
        loop0 = false;
        break;
      default: 
        cout << "Invalid number!\n";
        break;
    }
  }

  return 0;
}
