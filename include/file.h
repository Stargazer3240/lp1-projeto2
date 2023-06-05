#ifndef FILE_H
#define FILE_H

#include <fstream>

#include "playlist.h"

using std::fstream;

void read_file(List<Playlist*>& playlists, List<Music*>& musics, fstream& file);
void write_file(List<Playlist*>& playlists, fstream& file);

#endif
