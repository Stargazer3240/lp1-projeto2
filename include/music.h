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

  string getTitle() const;
  string getArtist() const;

  friend ostream& operator<<(ostream& out, const Music& music);
  friend ostream& operator<<(ostream& out, const Music* music);
};

#endif
