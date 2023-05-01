// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "interface.h"

int main() { 
  List<Playlist*> playlists;
  List<Music*> musics;

  Playlist play1("As 100 Melhores do Samba");
  Playlist play2("Alternative Metal");
  Music mus1("O mundo é um moinho", "Cartola");
  Music mus2("Saudosa Maloca", "Adoniran Barbosa");
  Music mus3("Toxicity", "System of a Down");
  Music mus4("Aerials", "System of a Down");
  Music mus5("Dead Memories", "Slipknot");

  playlists.push_back(&play1);
  playlists.push_back(&play2);
  musics.push_back(&mus1);
  musics.push_back(&mus2);
  musics.push_back(&mus3);
  musics.push_back(&mus4);
  musics.push_back(&mus5);

  playlists.get(0)->value->add_music(&mus1);
  playlists.get(0)->value->add_music(&mus4);
  playlists.get(0)->value->add_music(&mus2);
  playlists.get(1)->value->add_music(&mus3);
  playlists.get(1)->value->add_music(&mus4);
  playlists.get(1)->value->add_music(&mus5);
  playlists.get(1)->value->add_music(&mus2);

  // User Interface.
  while(main_menu(playlists, musics));

  return 0;
}
