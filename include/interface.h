// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "playlist.h"

using std::cin, std::getline;

#ifndef INTERFACE_H
#define INTERFACE_H

Music* new_music(string title, string artist);

Playlist* new_playlist(string name);

// Test if the input index is in a valid range [1,size].
template <typename T>
bool is_index_valid(const List<T*>& list, int index) {
  return index > 0 and index <= list.getSize();
}

template <typename T>
bool is_index_valid(const T* value, int index) {
  return index > 0 and index <= value->getSize();
}

bool main_menu(List<Playlist*>& playlists, List<Music*>& musics);

bool music_menu(List<Playlist*>& playlists, List<Music*>& musics);
void register_music(List<Music*>& musics);
void remove_music(List<Playlist*>& playlists, List<Music*>& musics);
void list_musics(const List<Music*>& musics);

bool playlist_menu(List<Playlist*>& playlists, const List<Music*>& musics);
void create_playlist(List<Playlist*>& playlists);
void delete_playlist(List<Playlist*>& playlists);
void list_playlists(const List<Playlist*>& playlists);
void list_playlist_musics(const List<Playlist*>& playlists);
void add_music_playlist(List<Playlist*>& playlists, const List<Music*>& musics);
void remove_music_playlist(List<Playlist*>& playlists);
void move_music_playlist(List<Playlist*>& playlists);
void next_on_playlist(List<Playlist*>& playlists);

#endif
