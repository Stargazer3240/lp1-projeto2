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

// Find occurences of a music, that will be removed, in all playlists
void clear_playlists(Music* desired_music, List<Playlist*>& playlists) {
  int size_i = playlists.getSize();
  int size_j{0};
  Playlist* test_playlist = nullptr;
  Music* test_music = nullptr;

  for (int i{0}; i < size_i; ++i) {
    test_playlist = playlists[i];
    size_j = test_playlist->getSize();
    for (int j{0}; j < size_j; ++j) {
      test_music = test_playlist->getMusics()[j];
      if (test_music != nullptr && test_music == desired_music) {
        test_playlist->remove_music(j);
        --j;
      }
    }
  }
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
    Music* desired_music{musics[index]};
    bool confirmation{user_confirmation("Music", desired_music)};
    if (confirmation) {
      clear_playlists(desired_music, playlists);
      musics.clear(index);
      cout << "Music removed!\n";
    }
  }
}

stringstream get_indexes(const string& wildcard) {
  cout << "What are the indexes of the" << wildcard << " (space separeted)? ";
  string to_remove;
  cin.ignore();
  getline(cin, to_remove);
  cout << '\n';
  stringstream ss(to_remove);

  return ss;
}

void remove_multiple_musics(List<Playlist*>& playlists, List<Music*>& musics) {
  list_musics(musics);
  stringstream ss(get_indexes("Musics to remove"));
  int counter{0};  // Keep track of how many elements were removed.
  int index;

  while (ss >> index) {
    index -= counter;  // As we remove, the music list size decreases
    if (!is_index_valid(musics, index)) {
      cout << "Invalid index!\n\n";
    } else {
      --index;
      Music* desired_music{musics[index]};
      bool confirmation{user_confirmation("Music", desired_music)};
      if (confirmation) {
        clear_playlists(desired_music, playlists);
        musics.clear(index);
        ++counter;
      }
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

void create_playlist_copy(List<Playlist*>& playlists) {
  list_playlists(playlists);
  cout << "What is the index of the Playlist to copy? ";
  int index;
  cin >> index;
  cout << '\n';
  if (!is_index_valid(playlists, index)) {
    cout << "Invalid index!\n\n";
  } else {
    --index;
    auto new_playlist = new Playlist(*playlists[index]);
    playlists.push_back(new_playlist);
    cout << "Operation done with success.\n\n";
  }
}

void create_playlist_union(List<Playlist*>& playlists) {
  list_playlists(playlists);
  stringstream ss(get_indexes("two Playlists to make an union from"));
  int first_index;
  ss >> first_index;
  int second_index;
  ss >> second_index;

  if (!is_index_valid(playlists, first_index) ||
      !is_index_valid(playlists, second_index)) {
    cout << "Invalid index!\n\n";
  } else {
    --first_index;
    --second_index;
    auto new_playlist =
        new Playlist(*playlists[first_index] + playlists[second_index]);
    cout << "What is the name of the new Playlist? ";
    string name;
    getline(cin, name);
    new_playlist->setName(name);
    playlists.push_back(new_playlist);
    cout << "Operation done with success.\n\n";
  }
}

void create_playlist_plus_music(List<Playlist*>& playlists,
                                const List<Music*>& musics) {
  int playlist_index{get_index(list_playlists, "Playlist to copy from", playlists)};
  int music_index{get_index(list_musics, "Music that will be added to it? ", musics)};

  if (!is_index_valid(playlists, playlist_index) ||
      !is_index_valid(musics, music_index)) {
    cout << "Invalid index!\n\n";
  } else {
    --playlist_index;
    --music_index;
    auto new_playlist =
        new Playlist(*playlists[playlist_index] + musics[music_index]);
    cout << "What is the name of the new Playlist? ";
    string name;
    getline(cin, name);
    new_playlist->setName(name);
    playlists.push_back(new_playlist);
    cout << "Operation done with success.\n\n";
  }
}

void create_playlist_difference(List<Playlist *> &playlists) { 
  list_playlists(playlists);
  stringstream ss(get_indexes("two Playlists to make a difference from"));
  int first_index;
  ss >> first_index;
  int second_index;
  ss >> second_index;

  if (!is_index_valid(playlists, first_index) ||
      !is_index_valid(playlists, second_index)) {
    cout << "Invalid index!\n\n";
  } else {
    --first_index;
    --second_index;
    auto new_playlist =
        new Playlist(*playlists[first_index] - playlists[second_index]);
    cout << "What is the name of the new Playlist? ";
    string name;
    getline(cin, name);
    new_playlist->setName(name);
    playlists.push_back(new_playlist);
    cout << "Operation done with success.\n\n";
  }
}

void create_playlist_min_music(List<Playlist *> &playlists) { 
  int playlist_index{get_index(list_playlists, "Playlist to copy from", playlists)};
  List<Music*> playlist_musics(playlists[playlist_index]->getMusics());
  int music_index{get_index(list_musics, "Music that will be removed from it? ", playlist_musics)};

  if (!is_index_valid(playlists, playlist_index) ||
      !is_index_valid(playlist_musics, music_index)) {
    cout << "Invalid index!\n\n";
  } else {
    --playlist_index;
    --music_index;
    auto new_playlist =
        new Playlist(*playlists[playlist_index] + playlist_musics[music_index]);
    cout << "What is the name of the new Playlist? ";
    string name;
    getline(cin, name);
    new_playlist->setName(name);
    playlists.push_back(new_playlist);
  }
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
    string playlist_name{playlists[index]->getName()};
    bool confirmation{user_confirmation("Playlist", playlist_name)};
    if (confirmation) {
      playlists.clear(index);
    }
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

void add_music_append(List<Playlist*>& playlists) {
  int index_play_a{get_index(list_playlists, "Playlist that will receive Musics", playlists)};
  int index_play_b{get_index(list_playlists, "Playlist that will send Musics", playlists)};

  if(!is_index_valid(playlists, index_play_b) || !is_index_valid(playlists, index_play_b)) {
    cout << "Invalid index!\n\n";
  } else {
    --index_play_a;
    --index_play_b;
    Playlist* play_a{playlists[index_play_a]};
    Playlist play_b{*playlists[index_play_b]};
    play_a->add_music(play_b);
    cout << "Operation done with success.\n\n";
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

void copy_playlist_minus(List<Playlist*>& playlists) {
  int index_play{get_index(list_playlists, "Playlist with the desired Musics", playlists)};
  auto music_list = playlists[index_play]->getMusics();
  int index_music{get_index(list_musics, "Music to be removed", music_list)};

  if(!is_index_valid(playlists, index_play) || !is_index_valid(music_list, index_music)) {
    cout << "Invalid index!\n\n";
  } else {
    --index_play;
    --index_music;
    auto desired_music = music_list[index_music];
    auto new_playlist = new Playlist(*playlists[index_play] - desired_music);
    cout << "What is the name of the new Playlist? ";
    string name;
    getline(cin, name);
    new_playlist->setName(name);
    playlists.push_back(new_playlist);
    cout << "Operation done with success.\n\n";
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

bool playlist_menu2(List<Playlist*>& playlists, const List<Music*>& musics) {
  cout << "IMDJ - Playlists Menu 2\n1 - Add Musics from one Playlist to "
          "another\n"
          "2 - Copy a Playlist minus one Music from it\n"
          "3 - Create Playlist by copying\n4 - Create Playlist by union\n"
          "5 - Create Playlist by copying plus new Music\n"
          "6 - Create Playlist by difference\n"
          "7 - Create Playlist by copying minus a Music\n"
          "0 - Return\n"
          "Choose an option: ";
  int index;
  cin >> index;
  cout << '\n';
  switch (index) {
    case 1:
      add_music_append(playlists);
      break;
    case 2:
      copy_playlist_minus(playlists);
      break;
    case 3:
      create_playlist_copy(playlists);
      break;
    case 4:
      create_playlist_union(playlists);
      break;
    case 5:
      create_playlist_plus_music(playlists, musics);
      break;
    case 6:
      create_playlist_difference(playlists);
      break;
    case 7:
      create_playlist_min_music(playlists);
      break;
    case 0:
      return false;
    default:
      cout << "Invalid number!\n";
      break;
  }
  return true;
}

bool playlist_menu(List<Playlist*>& playlists, const List<Music*>& musics) {
  cout << "IMDJ - Playlists Menu\n1 - Create Playlist\n"
          "2 - Delete Playlist\n3 - List Playlists\n4 - List Musics from a "
          "Playlist"
          "\n5 - Add Music to a Playlist\n6 - Remove Music from a Playlist\n"
          "7 - Move Music from a Playlist\n"
          "8 - Show next Music to play in a Playlist\n"
          "9 - Next page\n0 - Return\n"
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
    case 9:
      playlist_menu2(playlists, musics);
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
