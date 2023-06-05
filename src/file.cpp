#include "file.h"

#include <sstream>

using std::stringstream;

void read_file(List<Playlist*>& playlists, List<Music*>& musics,
               fstream& file) {
  if (!file.is_open()) {
    cout << "Failed to open file.\n";
    return;
  }

  string playlist_line;
  string playlist_name;
  string music_title;
  string music_artist;
  int i{0};
  bool should_add{false};

  while (!file.eof()) {
    getline(file, playlist_line);
    stringstream sstr(playlist_line);
    getline(sstr, playlist_name, ';');
    if (!playlist_name.empty()) {
      auto new_playlist = new Playlist(playlist_name);
      playlists.push_back(new_playlist);
    }
    while (!sstr.eof()) {
      getline(sstr, music_title, ':');
      getline(sstr, music_artist, ',');
      should_add = true;
      if (!music_title.empty() && !music_artist.empty()) {
        for (int j{0}; j < musics.getSize(); ++j) {
          if (musics[j]->getTitle() == music_title &&
              musics[j]->getArtist() == music_artist) {
            should_add = false;
          }
        }
        auto new_music = new Music(music_title, music_artist);
        playlists[i]->add_music(new_music);
        if (should_add) {
          musics.push_back(new_music);
        }
      }
    }
    ++i;
  }
}

void write_file(List<Playlist*>& playlists, fstream& file) {
  string music_title;
  string music_artist;

  for (int i{0}; i < playlists.getSize(); ++i) {
    file << playlists[i]->getName() << ';';
    auto musics = List<Music*>(playlists[i]->getMusics());
    for (int j{0}; j < playlists[i]->getSize(); ++j) {
      music_title = musics[j]->getTitle();
      music_artist = musics[j]->getArtist();
      file << music_title << ":" << music_artist << ",";
    }
    file << '\n';
  }
}
