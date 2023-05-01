// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "linked_list.h"
#include "music.h"

#ifndef PLAYLIST_H
#define PLAYLIST_H

/*!
 * @brief A class that represents a playlist.
 *
 * A playlist has a name and a linked list of musics.
 * @see Music; List
 */
class Playlist {
 private:
  string name;             /*!< The name of the playlist. */
  List<Music*> music_list; /*!< A list of musics. */
  int on_queue;            /*!< The index of the next song to be played. */

 public:
  /*!
   * @brief A constructor.
   *
   * Constructor that receives a name.
   * @see name;
   * @param name a string that represents a name.
   */
  explicit Playlist(string name);

  /*!
   * @brief A constructor.
   *
   * Constructor that receives a name and a list of musics.
   * @see name; music_list
   * @param name a string that represents a name.
   * @param music_list a const reference to a linked list of musics.
   */
  Playlist(string name, const List<Music*>& music_list);

  /*!
   * @brief A setter.
   *
   * Sets the name of the playlist.
   * @see name
   * @param name a string that represents a name.
   */
  void setName(string name);

  /*!
   * @brief A getter.
   *
   * Gets the name of the playlist.
   * @see name
   * @return The name of the playlist.
   */
  string getName() const;

  List<Music*> getMusics() const;

  /*!
   * @brief A getter.
   *
   * Gets the index of the next song to be played.
   * @see on_queue
   * @return The index of the next song to be played.
   */
  int getQueue() const;

  /*!
   * @brief Adds a music to the list of music.
   *
   * This method uses linked list's push_back method to add a music
   * to the end of the list of musics.
   * @param music a pointer to a music
   * @see List::push_back(); music_list
   */
  void add_music(Music* music);

  /*!
   * @brief Removes a music from the list of music.
   *
   * This method uses linked list's remove method to remove a music
   * at a certain position from the list of musics.
   * @param index the integer index of the desired music to remove.
   * @see List::remove(); music_list
   */
  void remove_music(int index);

  /*!
   * @brief Gives the next music on queue.
   *
   * This method checks the index of the next music on queue and gives
   * the music that will be played. If already in the end of queue, returns
   * a nullptr.
   * @see on_queue; music_list; List::get()
   * @return A pointer to the next music to be played.
   */
  Music* next_music();

  /*!
   * @brief Prints all the musics from the playlist.
   *
   * This method prints all the musics in the playlist's list of musics.
   * @param index optional integer parameter of the index of the first music to
   * start printing from. Defaults to the beginning of the list.
   * @see music_list; List::get(); List::getSize()
   */
  void print(int index = 0) const;

  /*!
   * @brief An I/O operator overloading.
   *
   * Sends the playlist name to the ostream.
   * @param out the output stream.
   * @param playlist a const reference to a playlist.
   * @see name; getName()
   * @return The name to the ostream.
   */
  friend ostream& operator<<(ostream& out, const Playlist& playlist);

  /*!
   * @brief An I/O operator overloading.
   *
   * Sends the playlist name to the ostream.
   * @param out the output stream.
   * @param playlist a const pointer to a playlist.
   * @see name; getName()
   * @return The name to the ostream.
   */
  friend ostream& operator<<(ostream& out, const Playlist* playlist);
};

#endif
