#include "playlist.h"

using std::cin, std::getline;

#ifndef INTERFACE_H
#define INTERFACE_H

Music* new_music(string title, string artist);

Playlist* new_playlist(string name);

template <typename T>
bool is_index_valid(const List<T*>& list, int index) {
  return index < 1 or index > list.getSize();
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
void list_musics_playlist(const List<Playlist*>& playlists);
void add_music_playlist(List<Playlist*>& playlists, const List<Music*>& musics);
void remove_music_playlist(List<Playlist*>& playlists,
                           const List<Music*>& musics);
void next_on_playlist(List<Playlist*>& playlists);

#endif
