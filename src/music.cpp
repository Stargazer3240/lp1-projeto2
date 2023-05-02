// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "music.h"

Music::Music(string title, string artist) {
  this->title = std::move(title);
  this->artist = std::move(artist);
}

void Music::setTitle(string title) { this->title = std::move(title); }

void Music::setArtist(string artist) { this->artist = std::move(artist); }

string Music::getTitle() const { return title; }

string Music::getArtist() const { return artist; }

ostream& operator<<(ostream& out, const Music& music) {
  return out << "Title: " << music.getTitle()
             << " | Artist: " << music.getArtist() << '\n';
}

ostream& operator<<(ostream& out, const Music* music) {
  return out << "Title: " << music->getTitle()
             << " | Artist: " << music->getArtist() << '\n';
}

bool operator==(const Music* music){
  if(this->title == music->title && this->artist == music->artist)
}
