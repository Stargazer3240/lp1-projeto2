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
  /*
    // User Interface.
    while (main_menu(playlists, musics)) {
    }
  */

  auto mus6 = new Music("O Pato", "João Gilberto");
  musics.push_back(mus6);

  List<Playlist*> playlists2;
  auto play3 = new Playlist("Chill Vibes");
  playlists2.push_back(play3);
  playlists2[0]->add_music(mus6);
  List<Playlist*> playlists3(playlists + playlists2);
  list_playlists(playlists3);

  playlists.add(playlists2);
  list_playlists(playlists);
  playlists.clear({play1, play2});
  list_playlists(playlists);

  List<Playlist*> playlists4;
  auto play4 = new Playlist("Pop");
  playlists4.push_back(play4);
  list_playlists(playlists4);
  Node<Playlist*> test_node;
  playlists4 >> test_node;
  cout << test_node.value;
  list_playlists(playlists4);

  playlists2.clear_nodes();
  delete play4;
  musics.clear_nodes();

  return 0;
}
