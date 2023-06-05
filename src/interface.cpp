// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "interface.h"

void register_music(List<Music*>& musics) {
  cout << "What is the title of the Music? ";
  cin.ignore();
  string title;
  getline(cin, title);
  cout << "What is the artist of the Music? ";
  string artist;
  getline(cin, artist);
  auto new_music = new Music(title, artist);
  musics.push_back(new_music);
  cout << "Music added with success!\n\n";
}

void remove_music(List<Playlist*>& playlists, List<Music*>& musics) {
  list_musics(musics);
  cout << "What is the index of the Music to remove? ";
  int index;
  cin >> index;
  cout << '\n';
  if (!is_index_valid(musics, index)) {
    cout << "Invalid index!\n\n";
  } else {
    --index;
    Music* desired_music = musics[index];
    cout << "This will remove Music:\n"
         << desired_music << "\nAre you sure [y/n]? ";
    char confirmation;
    cin >> confirmation;
    if (confirmation == 'y') {
      // Removing desired music from all playlists.
      int size_i = playlists.getSize();
      Playlist* test_playlist = nullptr;
      Music* test_music = nullptr;
      for (int i{0}; i < size_i; ++i) {
        test_playlist = playlists[i];
        for (int j{0}; j < test_playlist->getSize(); ++j) {
          test_music = test_playlist->getMusics()[j];
          if (test_music != nullptr && test_music == desired_music) {
            test_playlist->remove_music(j);
            j = 0;
          }
        }
      }
      musics.clear(index);
      cout << "Music removed!\n";
    } else if (confirmation == 'n') {
      cout << "Operation cancelled.\n\n";
    } else {
      cout << "Invalid operation.\n\n";
    }
    cout << '\n';
  }
}

void remove_multiple_musics(List<Playlist*>& playlists, List<Music*>& musics) {
  list_musics(musics);
  cout << "What is the index of the Musics to remove (space separeted)? ";
  string to_remove;
  cin.ignore();
  getline(cin, to_remove);
  cout << '\n';
  int index;
  stringstream ss(to_remove);
  int counter{0};
  while (ss >> index) {
    index -= counter;
    if (!is_index_valid(musics, index)) {
      cout << "Invalid index!\n\n";
    } else {
      --index;
      Music* desired_music = musics[index];
      cout << "This will remove Music:\n"
           << desired_music << "\nAre you sure [y/n]? ";
      char confirmation;
      cin >> confirmation;
      if (confirmation == 'y') {
        // Removing desired music from all playlists.
        int size_i = playlists.getSize();
        Playlist* test_playlist = nullptr;
        Music* test_music = nullptr;
        for (int i{0}; i < size_i; ++i) {
          test_playlist = playlists[i];
          for (int j{0}; j < test_playlist->getSize(); ++j) {
            test_music = test_playlist->getMusics()[j];
            if (test_music != nullptr && test_music == desired_music) {
              test_playlist->remove_music(j);
              j = 0;
            }
          }
        }
        musics.clear(index);
        cout << "Music removed!\n";
        ++counter;
      } else if (confirmation == 'n') {
        cout << "Operation cancelled.\n";
      } else {
        cout << "Invalid operation.\n";
      }
      cout << '\n';
    }
  }
}

void list_musics(const List<Music*>& musics) {
  if (musics.getSize() == 0) {
    cout << "No Music on the system!\n\n";
  } else {
    cout << "List of Musics:\n";
    musics.print();
    cout << '\n';
  }
}

bool music_menu(List<Playlist*>& playlists, List<Music*>& musics) {
  cout << "IMDJ - Musics Menu\n1 - Register Music\n"
          "2 - Remove Music\n3 - Remove Multiple Musics\n4 - List Musics\n0 - "
          "Return\n"
          "Choose an option: ";
  int index;
  cin >> index;
  cout << '\n';
  switch (index) {
    case 1:
      register_music(musics);
      break;
    case 2:
      remove_music(playlists, musics);
      break;
    case 3:
      remove_multiple_musics(playlists, musics);
      break;
    case 4:
      list_musics(musics);
      break;
    case 0:
      return false;
    default:
      cout << "Invalid number!\n";
      break;
  }
  return true;
}

void create_playlist(List<Playlist*>& playlists) {
  cout << "What is the name of the Playlist? ";
  cin.ignore();
  string name;
  getline(cin, name);
  auto new_playlist = new Playlist(name);
  playlists.push_back(new_playlist);
  cout << "Playlist created with success!\n\n";
}

void delete_playlist(List<Playlist*>& playlists) {
  list_playlists(playlists);
  cout << "What is the index of the Playlist to delete? ";
  int index;
  cin >> index;
  cout << '\n';
  if (!is_index_valid(playlists, index)) {
    cout << "Invalid index!\n\n";
  } else {
    --index;
    cout << "This will remove Playlist:\n"
         << playlists[index]->getName() << "\nAre you sure [y/n]? ";
    char confirmation;
    cin >> confirmation;
    if (confirmation == 'y') {
      playlists.clear(index);
      cout << "Playlist removed!\n";
    } else if (confirmation == 'n') {
      cout << "Operation cancelled.\n";
    } else {
      cout << "Invalid operation.\n";
    }
    cout << '\n';
  }
}

void list_playlists(const List<Playlist*>& playlists) {
  if (playlists.getSize() == 0) {
    cout << "No Playlist on the system!\n\n";
  } else {
    cout << "List of Playlists:\n";
    playlists.print();
    cout << '\n';
  }
}

void list_playlist_musics(const List<Playlist*>& playlists) {
  list_playlists(playlists);
  cout << "What is the index of the Playlist you want? ";
  int index;
  cin >> index;
  cout << '\n';
  if (!is_index_valid(playlists, index)) {
    cout << "Invalid index!\n\n";
  } else {
    --index;
    Playlist* desired_playlist = playlists[index];
    desired_playlist->print();
    cout << '\n';
  }
}

void add_music_playlist(List<Playlist*>& playlists,
                        const List<Music*>& musics) {
  list_playlists(playlists);
  cout << "What is the index of the Playlist you want? ";
  int playlist_index;
  cin >> playlist_index;
  cout << '\n';
  if (!is_index_valid(playlists, playlist_index)) {
    cout << "Invalid index!\n";
  } else {
    --playlist_index;
    if (musics.getSize() == 0) {
      cout << "No Music on the system!\n";
    } else {
      list_musics(musics);
      cout << "What is the index of the Music you want to add? ";
      int music_index;
      cin >> music_index;
      if (!is_index_valid(musics, music_index)) {
        cout << "Invalid index!\n\n";
      } else {
        --music_index;
        Playlist* desired_playlist = playlists[playlist_index];
        Music* desired_music = musics[music_index];
        desired_playlist->add_music(desired_music);
        cout << "Music added to playlist with success.\n\n";
      }
    }
  }
}

void remove_music_playlist(List<Playlist*>& playlists) {
  list_playlists(playlists);
  cout << "What is the index of the Playlist you want? ";
  int playlist_index;
  cin >> playlist_index;
  cout << '\n';
  if (!is_index_valid(playlists, playlist_index)) {
    cout << "Invalid index!\n";
  } else {
    --playlist_index;
    Playlist* desired_playlist = playlists[playlist_index];
    if (desired_playlist->getSize() == 0) {
      cout << "Playlist already empty!\n";
    } else {
      desired_playlist->print();
      cout << '\n';
      cout << "What is the index of the Music you want to remove? ";
      int music_index;
      cin >> music_index;
      if (!is_index_valid(desired_playlist, music_index)) {
        cout << "Invalid index!\n\n";
      } else {
        --music_index;
        desired_playlist->remove_music(music_index);
        cout << "Music removed from playlist with success.\n\n";
      }
    }
  }
}

void move_music_playlist(List<Playlist*>& playlists) {
  list_playlists(playlists);
  cout << "What is the index of the Playlist to move from? ";
  int cut_index;
  cin >> cut_index;
  cout << '\n';
  if (!is_index_valid(playlists, cut_index)) {
    cout << "Invalid index!\n\n";
  } else {
    --cut_index;
    list_playlists(playlists);
    cout << "What is the index of the Playlist to move to? ";
    int paste_index;
    cin >> paste_index;
    cout << '\n';
    if (!is_index_valid(playlists, paste_index)) {
      cout << "Invalid index!\n\n";
    } else if (cut_index + 1 == paste_index) {
      cout << "You selected the same playlist.\n\n";
    } else {
      --paste_index;
      Playlist* cut_playlist = playlists[cut_index];
      cut_playlist->print();
      cout << '\n';
      cout << "What is the index of the Music you want to move? ";
      int music_index;
      cin >> music_index;

      if (!is_index_valid(cut_playlist, music_index)) {
        cout << "Invalid index!\n\n";
      } else {
        --music_index;
        Music* chosen_music;
        chosen_music = cut_playlist->getMusics()[music_index];
        Playlist* paste_playlist = playlists[paste_index];
        paste_playlist->add_music(chosen_music);
        cut_playlist->remove_music(music_index);
        cout << "Music moved from playlists with success.\n\n";
      }
    }
  }
}

void next_on_playlist(List<Playlist*>& playlists) {
  list_playlists(playlists);
  cout << "What is the index of the Playlist you want? ";
  int index;
  cin >> index;
  cout << '\n';
  if (!is_index_valid(playlists, index)) {
    cout << "Invalid index!\n\n";
  } else {
    --index;
    Playlist* desired_playlist = playlists[index];
    Music* temp_music;
    temp_music = desired_playlist->next_music();
    if (temp_music == nullptr) {
      cout << "No Musics on this queue.\n\n";
    } else {
      cout << "#" << desired_playlist->getQueue() << " On Queue:\n";
      cout << temp_music;
      cout << '\n';
    }
  }
}

bool playlist_menu(List<Playlist*>& playlists, const List<Music*>& musics) {
  cout << "IMDJ - Playlists Menu\n1 - Create Playlist\n"
          "2 - Delete Playlist\n3 - List Playlists\n4 - List Musics from a "
          "Playlist"
          "\n5 - Add Music to a Playlist\n6 - Remove Music from a Playlist\n"
          "7 - Move Music from a Playlist\n"
          "8 - Show next Music to play in a Playlist\n0 - Return\n"
          "Choose an option: ";
  int index;
  cin >> index;
  cout << '\n';
  switch (index) {
    case 1:
      create_playlist(playlists);
      break;
    case 2:
      delete_playlist(playlists);
      break;
    case 3:
      list_playlists(playlists);
      break;
    case 4:
      list_playlist_musics(playlists);
      break;
    case 5:
      add_music_playlist(playlists, musics);
      break;
    case 6:
      remove_music_playlist(playlists);
      break;
    case 7:
      move_music_playlist(playlists);
      break;
    case 8:
      next_on_playlist(playlists);
      break;
    case 0:
      return false;
    default:
      cout << "Invalid number!\n";
      break;
  }
  return true;
}

bool main_menu(List<Playlist*>& playlists, List<Music*>& musics) {
  cout << "IMDJ - Main Menu\n1 - Manage Musics\n2 - Manage Playlists\n"
          "0 - Exit\nChoose an option: ";
  int index;
  cin >> index;
  cout << '\n';
  switch (index) {
    case 1:
      while (music_menu(playlists, musics)) {
      }
      break;
    case 2:
      while (playlist_menu(playlists, musics)) {
      }
      break;
    case 0:
      return false;
    default:
      cout << "Invalid number!\n";
      break;
  }
  return true;
}
