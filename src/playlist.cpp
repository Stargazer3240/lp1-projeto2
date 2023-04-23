// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "playlist.h"

Playlist::Playlist(string name) { this->name = name; }

Playlist::Playlist(string name, List<Music> musics) {
  this->name = name;
  this->musics = musics;
}

void Playlist::setName(string name) { this->name = name; }

string Playlist::getName() { return name; }

void Playlist::add_music(Music music) { musics.push_back(music); }

void Playlist::remove_music(Music music) { musics.remove(music); }
/*
Music Playlist::next_music(){

}

void Playlist::print_musics(){

}*/
