// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "interface.h"

int main() {
  List<Playlist*> playlists;
  List<Music*> musics;

  auto play1 = new Playlist("As 100 Melhores do Samba");
  auto play2 = new Playlist("Alternative Metal");
  auto mus1 = new Music("O mundo é um moinho", "Cartola");
  auto mus2 = new Music("Saudosa Maloca", "Adoniran Barbosa");
  auto mus3 = new Music("Toxicity", "System of a Down");
  auto mus4 = new Music("Aerials", "System of a Down");
  auto mus5 = new Music("Dead Memories", "Slipknot");

  playlists.push_back(play1);
  playlists.push_back(play2);
  musics.push_back(mus1);
  musics.push_back(mus2);
  musics.push_back(mus3);
  musics.push_back(mus4);
  musics.push_back(mus5);

  playlists[0]->add_music(mus1);
  playlists[0]->add_music(mus4);
  playlists[0]->add_music(mus2);
  playlists[1]->add_music(mus3);
  playlists[1]->add_music(mus4);
  playlists[1]->add_music(mus5);
  playlists[1]->add_music(mus2);
  // User Interface.
  // while (main_menu(playlists, musics)) {
  // }

  // List::operator+(List<T>& list_b);
  /* List<Playlist*> playlists2;
  auto play3 = new Playlist("Banana");
  playlists2.push_back(play3);
  List<Playlist*> playlists3(playlists + playlists2);
  playlists3.print(); */

  // List::operator>>(Node<T>*)
  /* auto music = new Music("Teste", "Testando");
  auto node = new Node<Music*>(music);
  musics.print();
  cout << '\n';
  musics >> node;
  musics.print();
  cout << '\n' << node->value;
  delete music;
  delete node; */

  // List::operator<<(Node<T>*)
  /* auto play3 = new Playlist("Oi");
  auto node = new Node<Playlist*>(play3);
  playlists << node;
  playlists.print(); */

  // Playlist::add_music(Playlist&)
  /*
  play1->print();
  cout << "\n";
  play1->add_music(*play2);
  play1->print();
  */

  // Playlist(Playlist&)
  /*
    auto play3 = new Playlist(*play1);
    play3->print();
  */

  // Playlist::remove_music(Playlist&)
  /*
    play1->print();
    play1->remove_music(*play2);
    cout << "\n";
    play1->print();
  */

  // Playlist::operator+(Playlist*)
  /* playlists[0]->print();
  playlists[1]->print();
  cout << "\n";
  Playlist play3(*playlists[0] + playlists[1]);
  play3.print(); */

  // Playlist::operator+(Music*)
  /* Playlist play3("Celular");
  Music mus6("Banana", "Pizza");
  Playlist play4(play3 + &mus6);
  play4.print(); */

  // Playlist::operator-(Playlist* playlist_b)
  /* play1->print();
  cout << '\n';
  play2->print();
  cout << '\n';
  Playlist play3(*play1 - play2);
  play3.print(); */

  // Playlist::operator-(Music* music)
  /* play1->print();
  cout << '\n' << mus2 << "\n\n";
  Playlist play3(*play1 - mus2);
  play3.print(); */

  playlists.clear_nodes();
  musics.clear_nodes();

  return 0;
}
