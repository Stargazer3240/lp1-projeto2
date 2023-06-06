// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#ifndef INTERFACE_H
#define INTERFACE_H

#include <sstream>

#include "playlist.h"

using std::cin, std::getline, std::stringstream;

// Receives a linked list and checks if the desired input index is in a valid
// range [0,size).
template <typename T>
bool is_index_valid(const List<T>& list, int index) {
  return index >= 0 and index < list.getSize();
}

// Receives a Playlist pointer and checks if the desired index is in a valid
// range [0,size).
template <typename T>
bool is_index_valid(const T playlist, int index) {
  return index >= 0 and index < playlist->getSize();
}

// Receives user confirmation previous to a delete operation.
template <typename T>
bool user_confirmation(const string& wildcard, T to_remove) {
  cout << "This will remove " << wildcard << ":\n"
       << to_remove << "\nAre you sure [y/n]? ";
  char confirmation;
  cin >> confirmation;
  bool to_return{false};
  if (confirmation == 'y') {
    cout << wildcard << " removed!\n";
    to_return = true;
  } else if (confirmation == 'n') {
    cout << "Operation cancelled.\n";
  } else {
    cout << "Invalid operation.\n";
  }
  cout << '\n';

  return to_return;
}

// Receives a function that prints a list, a string that will be send to output
// and the list that will be printed.
template <typename Func, typename List>
void print_string(Func func, const string& wildcard, const List& list) {
  func(list);
  cout << "What is the index of the " << wildcard << "? ";
}

template <typename List>
void print_string(const string& wildcard, const List& list) {
  cout << wildcard << ":\n";
  list.print();
  cout << '\n';
}

int get_index();
stringstream get_indexes();

// Receives a string and a playlist to print.
void print_string(const string& wildcard, const Playlist& playlist);
void invalid_index();
void operation_success();
void multiple_indexes();

bool main_menu(List<Playlist*>& playlists, List<Music*>& musics);

bool music_menu(List<Playlist*>& playlists, List<Music*>& musics);
void register_music(List<Music*>& musics);
void remove_music(List<Playlist*>& playlists, List<Music*>& musics);
void remove_multiple_musics(List<Playlist*>& playlists, List<Music*>& musics);
void list_musics(const List<Music*>& musics);
void clear_playlists(Music* desired_music, List<Playlist*>& playlists);

void playlist_renaming(Playlist* play, List<Playlist*>& playlists);

bool playlist_menu(List<Playlist*>& playlists, const List<Music*>& musics);
void create_playlist(List<Playlist*>& playlists);
void delete_playlist(List<Playlist*>& playlists);
void list_playlists(const List<Playlist*>& playlists);
void list_playlist_musics(const List<Playlist*>& playlists);
void add_music_playlist(List<Playlist*>& playlists, const List<Music*>& musics);
void remove_music_playlist(List<Playlist*>& playlists);
void move_music_playlist(List<Playlist*>& playlists);
void next_on_playlist(List<Playlist*>& playlists);

bool playlist_menu2(List<Playlist*>& playlists, const List<Music*>& musics);
void add_music_append(List<Playlist*>& playlists);
void copy_playlist_minus(List<Playlist*>& playlists);
void create_playlist_copy(List<Playlist*>& playlists);
void create_playlist_union(List<Playlist*>& playlists);
void create_playlist_plus_music(List<Playlist*>& playlists,
                                const List<Music*>& musics);
void create_playlist_difference(List<Playlist*>& playlists);
#endif
