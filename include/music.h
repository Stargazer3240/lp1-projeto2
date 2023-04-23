// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include <iostream>
#include <utility>
#include <string>

using std::string, std::ostream, std::cout, std::move;

#ifndef MUSIC_H
#define MUSIC_H

class Music {
 private:
  string title;
  string artist;

 public:
  Music() = default;

  Music(string title, string artist);

  void setTitle(string title);
  void setArtist(string artist);

  string getTitle();
  string getArtist();

  friend void operator<<(ostream& os, const Music& to_print) {
    os << "Title: " << to_print.title << '\n'
       << "Artist: " << to_print.artist << '\n';
  }

  bool operator==(Music to_compare);
};

#endif
