// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "playlist.h"

Playlist::Playlist(string name) {
  this->name = std::move(name);
  on_queue = 0;
}

Playlist::Playlist(Playlist& playlist) {
  this->name = playlist.name;
  for (int i{0}; i < playlist.music_list.getSize(); ++i) {
    this->music_list.push_back(playlist.music_list[i]);
  }
  this->on_queue = playlist.on_queue;
}

Playlist::~Playlist() { music_list.remove_nodes(); }

void Playlist::setName(string name) { this->name = std::move(name); }

string Playlist::getName() const { return name; }

List<Music*>& Playlist::getMusics() { return music_list; }

int Playlist::getQueue() const { return on_queue; }

int Playlist::getSize() const { return music_list.getSize(); }

void Playlist::add_music(Music* music) { music_list.push_back(music); }

void Playlist::add_music(Playlist& playlist) {
  if (this->getSize() == 0) {
    for (int i{0}; i < playlist.getSize(); ++i) {
      this->music_list.push_back(playlist.music_list[i]);
    }
  } else {
    this->music_list.add(playlist.getMusics());
  }
}

void Playlist::remove_music(int index) { music_list.remove(index); }

int Playlist::remove_music(const Playlist& playlist) {
  int sum{0};
  for (int i{0}; i < playlist.music_list.getSize(); ++i) {
    if (this->music_list.search(playlist.music_list[i])) {
      this->music_list.remove(music_list.find(playlist.music_list[i]));
      ++sum;
    }
  }

  return sum;
}

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
    cout << index + 1 << ". " << music_list[index] << '\n';
    print(++index);
  }
}

Playlist Playlist::operator+(Playlist* playlist_b) {
  Playlist playlist_a(*this);
  bool should_add;

  for (int i{0}; i < playlist_b->getSize(); ++i) {
    should_add = true;
    for (int j{0}; j < playlist_a.getSize(); ++j) {
      auto music_b = playlist_b->getMusics()[i];
      auto music_a = playlist_a.getMusics()[j];
      if (music_b->getTitle() == music_a->getTitle() &&
          music_b->getArtist() == music_a->getArtist()) {
        should_add = false;
      }
    }
    if (should_add) {
      playlist_a.add_music(playlist_b->getMusics()[i]);
    }
  }

  return playlist_a;
}

Playlist Playlist::operator+(Music* music) {
  Playlist playlist_a(*this);

  playlist_a.add_music(music);

  return playlist_a;
}

Playlist Playlist::operator-(Playlist* playlist_b) {
  Playlist playlist_a(*this);
  for (int i{0}; i < playlist_b->getSize(); ++i) {
    for (int j{0}; j < playlist_a.getSize(); ++j) {
      auto music_b = playlist_b->getMusics()[i];
      auto music_a = playlist_a.getMusics()[j];
      if (music_b->getTitle() == music_a->getTitle() &&
          music_b->getArtist() == music_a->getArtist()) {
        playlist_a.remove_music(j);
      }
    }
  }
  return playlist_a;
}

Playlist Playlist::operator-(Music* music) {
  Playlist playlist(*this);

  if (playlist.getMusics().search(music)) {
    playlist.remove_music(playlist.getMusics().find(music));
  }

  return playlist;
}

void Playlist::operator>>(Music* music) {
  if (getSize() > 0) {
    int last{getSize() - 1};
    string title = getMusics()[last]->getTitle();
    string artist = getMusics()[last]->getArtist();
    music->setTitle(title);
    music->setArtist(artist);
    this->remove_music(last);
    return;
  }

  music = nullptr;
}

void Playlist::operator<<(Music* music) {
  if (music != nullptr) {
    add_music(music);
  }
}

ostream& operator<<(ostream& out, const Playlist& playlist) {
  return out << "" << playlist.getName();
}

ostream& operator<<(ostream& out, const Playlist* playlist) {
  return out << "" << playlist->getName();
}
