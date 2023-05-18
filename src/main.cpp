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

  playlists.get(0)->value->add_music(mus1);
  playlists.get(0)->value->add_music(mus4);
  playlists.get(0)->value->add_music(mus2);
  playlists.get(1)->value->add_music(mus3);
  playlists.get(1)->value->add_music(mus4);
  playlists.get(1)->value->add_music(mus5);
  playlists.get(1)->value->add_music(mus2);
/*
  // User Interface.
  while (main_menu(playlists, musics)) {
  }
*/

  return 0;
}
