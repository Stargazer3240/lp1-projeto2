// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "linked_list.h"
#include "music.h"

#ifndef PLAYLIST_H
#define PLAYLIST_H

class Playlist {
 private:
  string name;
  List<Music*> music_list;
  int on_queue;

 public:
  explicit Playlist(string name);
  Playlist(string name, const List<Music*>& music_list);

  void setName(string name);

  string getName();

  void add_music(Music* music);
  void remove_music(int index);
  Music* next_music();
  void print(int index = 0);
};

#endif
