// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include <iostream>

using std::cout;

#include "linked_list.h"
#include "music.h"

#ifndef PLAYLIST_H
#define PLAYLIST_H

class Playlist {
 private:
  string name;
  List<Music> musics;

 public:
  Playlist(string name);
  Playlist(string name, List<Music> musics);

  void setName(string name);

  string getName();

  void add_music(Music music);
  void remove_music(Music music);
  Music next_music();
  void print_musics();
};

#endif
