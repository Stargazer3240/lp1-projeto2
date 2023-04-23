// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "music.h"

Music::Music(string title, string artist) {
  this->title = title;
  this->artist = artist;
}

void Music::setTitle(string title) { this->title = move(title); }

void Music::setArtist(string artist) { this->artist = move(artist); }

string Music::getTitle() { return title; }

string Music::getArtist() { return artist; }

bool Music::operator==(Music to_compare) {
  if (title == to_compare.title && artist == to_compare.artist) {
    return true;
  }

  return false;
}
