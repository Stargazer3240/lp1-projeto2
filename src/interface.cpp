// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "interface.h"

int get_index() {
  int index;
  cin >> index;
  cout << '\n';
  return index - 1;
}

stringstream get_indexes() {
  string indexes;
  cin.ignore();
  getline(cin, indexes);
  cout << '\n';
  stringstream ss(indexes);

  return ss;
}

void print_string(const string& wildcard, const Playlist& playlist) {
  playlist.print();
  cout << "What is the index of the " << wildcard << "? ";
}

void invalid_index() { cout << "Invalid index!\n\n"; }

void operation_success() { cout << "Operation done with success.\n\n"; }

bool main_menu(List<Playlist*>& playlists, List<Music*>& musics) {
  cout << "IMDJ - Main Menu\n1 - Manage Musics\n2 - Manage Playlists\n"
          "0 - Exit\nChoose an option: ";
  int index{get_index() + 1};
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

bool music_menu(List<Playlist*>& playlists, List<Music*>& musics) {
  cout << "IMDJ - Musics Menu\n1 - Register Music\n"
          "2 - Remove Music\n3 - Remove Multiple Musics\n4 - List Musics\n0 - "
          "Return\n"
          "Choose an option: ";
  int index{get_index() + 1};
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
  operation_success();
}

void remove_music(List<Playlist*>& playlists, List<Music*>& musics) {
  print_string(list_musics, "Music to remove", musics);
  int index{get_index()};
  if (!is_index_valid(musics, index)) {
    invalid_index();
  } else {
    --index;
    Music* desired_music{musics[index]};
    bool confirmation{user_confirmation("Music", desired_music)};
    if (confirmation) {
      clear_playlists(desired_music, playlists);
      musics.clear(index);
      operation_success();
    }
  }
}

void remove_multiple_musics(List<Playlist*>& playlists, List<Music*>& musics) {
  print_string(list_musics, "Musics to remove", musics);
  stringstream ss(get_indexes());
  int counter{0};  // Keep track of how many elements were removed.
  int index;
  while (ss >> index) {
    index -= counter - 1;  // As we remove, the music list size decreases
    if (!is_index_valid(musics, index)) {
      invalid_index();
    } else {
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
    print_string("List of Musics", musics);
  }
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

bool playlist_menu(List<Playlist*>& playlists, const List<Music*>& musics) {
  cout << "IMDJ - Playlists Menu\n1 - Create Playlist\n"
          "2 - Delete Playlist\n3 - List Playlists\n4 - List Musics from a "
          "Playlist"
          "\n5 - Add Music to a Playlist\n6 - Remove Music from a Playlist\n"
          "7 - Move Music from a Playlist\n"
          "8 - Show next Music to play in a Playlist\n"
          "9 - Next page\n0 - Return\n"
          "Choose an option: ";
  int index{get_index() + 1};
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

void create_playlist(List<Playlist*>& playlists) {
  cout << "What is the name of the Playlist? ";
  cin.ignore();
  string name;
  getline(cin, name);
  auto new_playlist = new Playlist(name);
  playlists.push_back(new_playlist);
  operation_success();
}

void delete_playlist(List<Playlist*>& playlists) {
  print_string(list_playlists, "Playlist to delete", playlists);
  int index{get_index()};
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
    print_string("List of Playlists", playlists);
  }
}

void list_playlist_musics(const List<Playlist*>& playlists) {
  print_string(list_playlists, "Playlist to print", playlists);
  int index{get_index()};
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
  print_string(list_playlists, "Playlist you want", playlists);
  int playlist_index{get_index()};
  if (!is_index_valid(playlists, playlist_index)) {
    invalid_index();
  } else {
    if (musics.getSize() == 0) {
      cout << "No Music on the system!\n";
    } else {
      print_string(list_musics, "Music you want to add", musics);
      int music_index{get_index()};
      if (!is_index_valid(musics, music_index)) {
        invalid_index();
      } else {
        Playlist* desired_playlist = playlists[playlist_index];
        Music* desired_music = musics[music_index];
        desired_playlist->add_music(desired_music);
        operation_success();
      }
    }
  }
}

void remove_music_playlist(List<Playlist*>& playlists) {
  print_string(list_playlists, "Playlist you want", playlists);
  int playlist_index{get_index()};
  if (!is_index_valid(playlists, playlist_index)) {
    invalid_index();
  } else {
    Playlist* desired_playlist = playlists[playlist_index];
    if (desired_playlist->getSize() == 0) {
      cout << "Playlist already empty!\n";
    } else {
      print_string("Music you want to remove", *desired_playlist);
      int music_index{get_index()};
      if (!is_index_valid(desired_playlist, music_index)) {
        invalid_index();
      } else {
        desired_playlist->remove_music(music_index);
        operation_success();
      }
    }
  }
}

void move_music_playlist(List<Playlist*>& playlists) {
  print_string(list_playlists, "Playlist to move from", playlists);
  int cut_index{get_index()};
  print_string(list_playlists, "Playlist to move to", playlists);
  int paste_index{get_index()};
  if (cut_index == paste_index) {
    cout << "You selected the same playlist.\n\n";
  } else if (!is_index_valid(playlists, paste_index) ||
             !is_index_valid(playlists, cut_index)) {
    invalid_index();
  } else {
    Playlist* cut_playlist = playlists[cut_index];
    print_string("Music you want to move", *cut_playlist);
    int music_index{get_index()};
    if (!is_index_valid(cut_playlist, music_index)) {
      invalid_index();
    } else {
      Music* choosen_music{cut_playlist->getMusics()[music_index]};
      Playlist* paste_playlist{playlists[paste_index]};
      paste_playlist->add_music(choosen_music);
      cut_playlist->remove_music(music_index);
      operation_success();
    }
  }
}

void next_on_playlist(List<Playlist*>& playlists) {
  print_string(list_playlists, "Playlist you want", playlists);
  int index{get_index()};
  if (!is_index_valid(playlists, index)) {
    invalid_index();
  } else {
    Playlist* desired_playlist{playlists[index]};
    Music* temp_music{desired_playlist->next_music()};
    if (temp_music == nullptr) {
      cout << "No Musics on this queue.\n\n";
    } else {
      cout << "#" << desired_playlist->getQueue() << " On Queue:\n"
           << temp_music << '\n';
    }
  }
}

void playlist_renaming(Playlist* play, List<Playlist*>& playlists) {
  cout << "What is the name of the new Playlist? ";
  string name;
  cin.ignore();
  getline(cin, name);
  play->setName(name);
  playlists.push_back(play);
}

bool playlist_menu2(List<Playlist*>& playlists, const List<Music*>& musics) {
  cout << "IMDJ - Playlists Menu 2\n1 - Add Musics from one Playlist to "
          "another\n"
          "2 - Copy a Playlist minus one Music from it\n"
          "3 - Create Playlist by copying\n4 - Create Playlist by union\n"
          "5 - Create Playlist by copying plus new Music\n"
          "6 - Create Playlist by difference\n"
          "0 - Return\n"
          "Choose an option: ";
  int index{get_index() + 1};
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
    case 0:
      return false;
    default:
      cout << "Invalid number!\n";
      break;
  }
  return true;
}

void add_music_append(List<Playlist*>& playlists) {
  print_string(list_playlists, "Playlist that will receive Musics", playlists);
  int index_a{get_index()};
  print_string(list_playlists, "Playlist that will send Musics", playlists);
  int index_b{get_index()};

  if (!is_index_valid(playlists, index_a) ||
      !is_index_valid(playlists, index_b)) {
    invalid_index();
  } else {
    Playlist* play_a{playlists[index_a]};
    Playlist play_b{*playlists[index_b]};
    play_a->add_music(play_b);
    operation_success();
  }
}

void copy_playlist_minus(List<Playlist*>& playlists) {
  print_string(list_playlists, "Playlist to copy from", playlists);
  int playlist_index{get_index()};
  if (!is_index_valid(playlists, playlist_index)) {
    invalid_index();
    return;
  }
  List<Music*> playlist_musics(playlists[playlist_index]->getMusics());
  print_string(list_musics, "Music that will be removed from it",
               playlist_musics);
  int music_index{get_index()};

  if (!is_index_valid(playlist_musics, music_index)) {
    cout << "Invalid index!\n\n";
  } else {
    auto new_playlist =
        new Playlist(*playlists[playlist_index] - playlist_musics[music_index]);
    playlist_renaming(new_playlist, playlists);
    operation_success();
  }
}

void create_playlist_copy(List<Playlist*>& playlists) {
  print_string(list_playlists, "two Playlists to to copy?", playlists);
  int index;
  cin >> index;
  cout << '\n';
  if (!is_index_valid(playlists, index)) {
    invalid_index();
  } else {
    --index;
    auto new_playlist = new Playlist(*playlists[index]);
    playlists.push_back(new_playlist);
    operation_success();
  }
}

void create_playlist_union(List<Playlist*>& playlists) {
  print_string(list_playlists, "two Playlists to make an union from",
               playlists);
  stringstream ss(get_indexes());
  int first_index;
  ss >> first_index;
  int second_index;
  ss >> second_index;
  --first_index;
  --second_index;
  if (!is_index_valid(playlists, first_index) ||
      !is_index_valid(playlists, second_index)) {
    invalid_index();
  } else {
    auto new_playlist =
        new Playlist(*playlists[first_index] + playlists[second_index]);
    playlist_renaming(new_playlist, playlists);
    operation_success();
  }
}

void create_playlist_plus_music(List<Playlist*>& playlists,
                                const List<Music*>& musics) {
  print_string(list_playlists, "Playlist to copy from", playlists);
  int playlist_index{get_index()};
  print_string(list_musics, "Music that will be added to it", musics);
  int music_index{get_index()};

  if (!is_index_valid(playlists, playlist_index) ||
      !is_index_valid(musics, music_index)) {
    invalid_index();
  } else {
    auto new_playlist =
        new Playlist(*playlists[playlist_index] + musics[music_index]);
    playlist_renaming(new_playlist, playlists);
    operation_success();
  }
}

void create_playlist_difference(List<Playlist*>& playlists) {
  print_string(list_playlists, "two Playlists to make a difference from",
               playlists);
  stringstream ss(get_indexes());
  int first_index;
  ss >> first_index;
  --first_index;
  int second_index;
  ss >> second_index;
  --second_index;

  if (!is_index_valid(playlists, first_index) ||
      !is_index_valid(playlists, second_index)) {
    invalid_index();
  } else {
    auto new_playlist =
        new Playlist(*playlists[first_index] - playlists[second_index]);
    playlist_renaming(new_playlist, playlists);
    operation_success();
  }
}
