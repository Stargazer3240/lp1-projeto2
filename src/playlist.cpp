// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "playlist.h"

// Playlist::Playlist(string name) { this->name = move(name); }

Playlist::Playlist(string name, const List<Music>& musics) {
  this->name = std::move(name);
  this->musics = musics;
}

void Playlist::setName(string name) { this->name = std::move(name); }

string Playlist::getName() { return name; }

void Playlist::add_music() {}

void Playlist::remove_music() {}

/*Music Playlist::next_music(){

}*/

void Playlist::print_musics() {}
