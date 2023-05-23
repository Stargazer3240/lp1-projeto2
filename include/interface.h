// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#ifndef INTERFACE_H
#define INTERFACE_H

#include "playlist.h"

using std::cin, std::getline;

// Receives a linked list and checks if the desired input index is in a valid
// range [1,size].
template <typename T>
bool is_index_valid(const List<T*>& list, int index) {
  return index > 0 and index <= list.getSize();
}

// Receives a Playlist pointer and checks if the desired index is in a valid
// range [1,size].
template <typename T>
bool is_index_valid(const T playlist, int index) {
  return index > 0 and index <= playlist->getSize();
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
