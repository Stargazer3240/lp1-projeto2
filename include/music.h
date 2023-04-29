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
 * A music is made of a title and an artist.
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
   * Constructor that receives a title and an arstist.
   * @see title; artist
   * @param title a string that represents a title.
   * @param artist a string that represents an artist.
   */
  Music(string title, string artist);

  /*!
   * @brief A setter.
   *
   * Sets the title of the music.
   * @see title
   * @param title a string that represents a title.
   */
  void setTitle(string title);

  /*!
   * @brief A setter.
   *
   * Sets the artist of the music.
   * @see artist
   * @param artist a string that represents an artist.
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
   * Sends the title and the artist of a music to the ostream.
   * @param out the output stream.
   * @param music a reference to a music.
   * @see title; artist; getTitle(); getArtist()
   * @return The title and the artist to the ostream.
   */
  friend ostream& operator<<(ostream& out, const Music& music);

  /*!
   * @brief An I/O operator overloading.
   *
   * Sends the title and the artist of a music to the ostream.
   * @param out the output stream.
   * @param music a pointer to a music.
   * @see title; artist; getTitle(); getArtist()
   * @return The title and the artist to the ostream.
   */
  friend ostream& operator<<(ostream& out, const Music* music);
};

#endif
