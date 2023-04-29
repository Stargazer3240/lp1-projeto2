// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include <iostream>
#include <string>
#include <utility>

using std::string, std::ostream, std::cout;

#ifndef MUSIC_H
#define MUSIC_H

/*!
 * @brief A class that represents a music.
 *
 * A music is made of a Title and an Artist.
 */
class Music {
 private:
  string title;  /*!< The title of the music. */
  string artist; /*!< The artist of the music. */

 public:
  /*!
   * @brief A constructor.
   *
   * Default empty constructor.
   */
  Music() = default;

  /*!
   * @brief A constructor.
   *
   * Constructor that receives the title and the arstist of the music.
   * @see title; artist
   * @param title a string that represents the title of the music.
   * @param artist a string that represents the artist of the music.
   */
  Music(string title, string artist);

  /*!
   * @brief A setter.
   *
   * Sets the title of the music.
   * @see title
   * @param title a string that represents the title of the music.
   */
  void setTitle(string title);

  /*!
   * @brief A setter.
   *
   * Sets the artist of the music.
   * @see artist
   * @param artist a string that represents the artist of the music.
   */
  void setArtist(string artist);

  /*!
   * @brief A getter.
   *
   * Gets the title of the music.
   * @see title
   * @return The title of the music.
   */
  string getTitle() const;

  /*!
   * @brief A getter.
   *
   * Gets the artist of the music.
   * @see artist
   * @return The artist of the music.
   */
  string getArtist() const;

  /*!
   * @brief An I/O operator overloading.
   *
   * Sends the title and the artist of the music to the ostream.
   * @param out The output stream.
   * @param music A reference to a music.
   * @see title; artist; getTitle(); getArtist()
   * @return The title and the artist to the ostream.
   */
  friend ostream& operator<<(ostream& out, const Music& music);

  /*!
   * @brief An I/O operator overloading.
   *
   * Sends the title and the artist of the music to the ostream.
   * @param out The output stream.
   * @param music A pointer to a music.
   * @see title; artist; getTitle(); getArtist()
   * @return The title and the artist to the ostream.
   */
  friend ostream& operator<<(ostream& out, const Music* music);
};

#endif
