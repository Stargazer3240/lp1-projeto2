// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include <iostream>
#include <string>
#include <utility>

using std::string, std::ostream, std::cout;

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

  friend void operator<<(ostream& out, const Music& to_print) {
    out << "Title: " << to_print.title << '\n'
        << "Artist: " << to_print.artist << '\n';
  }

  bool operator==(const Music& to_compare);
};

#endif
