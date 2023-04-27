// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include <string>
#include <utility>

using std::string, std::ostream;

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
};

#endif
