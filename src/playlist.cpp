// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "playlist.h"

Playlist::Playlist(string name) {
  this->name = std::move(name);
  on_queue = 0;
}

Playlist::~Playlist() { music_list.remove_nodes(); }

void Playlist::setName(string name) { this->name = std::move(name); }

string Playlist::getName() const { return name; }

List<Music*>& Playlist::getMusics() { return music_list; }

int Playlist::getQueue() const { return on_queue; }

int Playlist::getSize() const { return music_list.getSize(); }

void Playlist::add_music(Music* music) { music_list.push_back(music); }

void Playlist::remove_music(int index) { music_list.remove(index); }

Music* Playlist::next_music() {
  Music* to_play;
  if (on_queue < music_list.getSize()) {
    to_play = music_list[on_queue];
    ++on_queue;
  } else {
    to_play = nullptr;
  }

  return to_play;
}

void Playlist::print(int index) const {
  if (music_list.getSize() == 0) {
    cout << getName() << " is empty!\n";
  } else if (index < music_list.getSize()) {
    cout << index + 1 << ". " << music_list[index];
    print(++index);
  }
}

ostream& operator<<(ostream& out, const Playlist& playlist) {
  return out << "" << playlist.getName() << '\n';
}

ostream& operator<<(ostream& out, const Playlist* playlist) {
  return out << "" << playlist->getName() << '\n';
}
