// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "playlist.h"

using std::cin, std::getline;

// Creates a music on Heap for usage with List::push_back.
Music* new_music(string title, string artist){
  auto new_music = new Music(std::move(title), std::move(artist));
  return new_music;
}

// Creates a playlist on Heap for usage with List::push_back.
Playlist* new_playlist(string name){
  auto new_playlist = new Playlist(std::move(name));
  return new_playlist;
}

template <typename T>
bool is_index_valid(List<T*>& list, int index) {
  return index < 1 or index > list.getSize();
}

void register_music(List<Music*>& musics) {
  cout << "What is the title of the Music? ";
  cin.ignore();
  string title;
  getline(cin, title);
  cout << "What is the artist of the Music? ";
  string artist;
  getline(cin, artist);
  musics.push_back(new_music(title, artist)); 
  cout << "Music added with success!\n";
}

void remove_music(List<Playlist*>& playlists, List<Music*>& musics){
  cout << "What is the index of the Music to remove? ";
  int index;
  cin >> index;
  cout << '\n';

  if(is_index_valid(musics, index)){
    cout << "Invalid index!\n";
  } else {
    --index;
    cout << "This will remove Music:\n" << musics.get(index)->value <<
      "Are you sure [y/n]? ";
    char confirmation;
    cin >> confirmation;

    if(confirmation == 'y') {
      musics.remove(index);
      cout << "Music removed!\n";
    } else if(confirmation == 'n') {
      cout << "Operation cancelled.\n";
    } else {
      cout << "Invalid operation.\n";
    }
  }
}

void list_musics(List<Music*>& musics){
  if(musics.getSize() == 0){
    cout << "No Music on the system!\n";
  } else {
    cout << "\nList of Musics:\n";
    musics.print();
    cout << '\n';
  }
}

bool music_menu(List<Playlist*>& playlists, List<Music*>& musics){ 
    cout << "IMDJ - Musics Menu\n1 - Register Music\n"
      "2 - Remove Music\n3 - List Musics\n0 - Return\n"
      "Choose an option: ";
    int index;
    cin >> index;
    cout << '\n';

    switch(index){
      case 1:
        register_music(musics);
        break;
      case 2:
        remove_music(playlists, musics);
        break;
      case 3:
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
  playlists.push_back(new_playlist(name)); 
  cout << "Playlist created with success!\n";
}

void delete_playlist(List<Playlist*> playlists){ 
  cout << "What is the index of the Playlist to delete? ";
  int index;
  cin >> index;
  cout << '\n';

  if(is_index_valid(playlists, index)){
    cout << "Invalid index!\n";
  } else {
    --index;
    cout << "This will remove Playlist:\n" << playlists.get(index)->value->getName() <<
      "\nAre you sure [y/n]? ";
    char confirmation;
    cin >> confirmation;

    if(confirmation == 'y') {
      playlists.remove(index);
      cout << "Playlist removed!\n";
    } else if(confirmation == 'n') {
      cout << "Operation cancelled.\n";
    } else {
      cout << "Invalid operation.\n";
    }
  }
}

void list_playlists(List<Playlist*>& playlists) {
  if(playlists.getSize() == 0){
    cout << "No Playlist on the system!\n";
  } else {
    cout << "List of Playlists:\n";
    playlists.print();
    cout << '\n';
  }
}

void list_musics_playlist(List<Playlist*>& playlists) {
  cout << "What is the index of the Playlist you want? ";
  int index;
  cin >> index;
  cout << '\n';

  if(is_index_valid(playlists, index)){
    cout << "Invalid index!\n";
  } else {
    --index;
    playlists.get(index)->value->print(); 
    cout << '\n';
  }
}

void add_music_playlist(List<Playlist*>& playlists, List<Music*> musics) {
  cout << "What is the index of the Playlist you want? ";
  int playlist_index;
  cin >> playlist_index;
  cout << '\n';

  if(is_index_valid(playlists, playlist_index)){
    cout << "Invalid index!\n";
  } else {
    --playlist_index;
    
    if(musics.getSize() == 0){
      cout << "No Music on the system!\n";
    } else {
      cout << "\nList of Musics:\n";
      musics.print();
      cout << '\n';
      cout << "What is the index of the Music you want to add? ";
      int music_index;
      cin >> music_index;
      
      if(is_index_valid(musics, music_index)){
        cout << "Invalid index!\n";
      } else {
        Music* temp_music;
        temp_music = musics.get(music_index)->value;
        playlists.get(playlist_index)->value->add_music(temp_music);
        cout << "Music added to playlist with success.\n";
      }
    }
  }
}

void remove_music_playlist(List<Playlist*>& playlists, List<Music*> musics) {
  cout << "What is the index of the Playlist you want? ";
  int playlist_index;
  cin >> playlist_index;
  cout << '\n';
  if(is_index_valid(playlists, playlist_index)){
    cout << "Invalid index!\n";
  } else {
    --playlist_index;

    if(musics.getSize() == 0){
      cout << "No Music on the system!\n";
    } else {
      playlists.get(playlist_index)->value->print(); 
      cout << '\n';
      cout << "What is the index of the Music you want to add? ";
      int music_index;
      cin >> music_index;
      
      if(is_index_valid(musics, music_index)){
        cout << "Invalid index!\n";
      } else {
        playlists.get(playlist_index)->value->remove_music(music_index);
        cout << "Music removed from playlist with success.\n";
      }
    }
  }
}

void next_on_playlist(List<Playlist*>& playlists) {
  cout << "What is the index of the Playlist you want? ";
  int index;
  cin >> index;
  cout << '\n';

  if(is_index_valid(playlists, index)){
    cout << "Invalid index!\n";
  } else {
    --index;
    Music* temp_music;
    temp_music = playlists.get(index)->value->next_music();

    if(temp_music == nullptr){
      cout << "No Musics on this queue.\n";
    } else {
      cout << "\n#" << playlists.get(index)->value->getQueue() << " On Queue:\n";
      cout << temp_music; 
    }
  }
}

bool playlist_menu(List<Playlist*>& playlists, List<Music*> musics){
    cout << "IMDJ - Playlists Menu\n1 - Create Playlist\n"
      "2 - Delete Playlist\n3 - List Playlists\n4 - List Musics from a Playlist"
      "\n5 - Add Music to a Playlist\n6 - Remove Music from a Playlist\n"
      "7 - Move Music from a Playlist\n"
      "8 - Show next Music to play in a Playlist\n0 - Return\n"
      "Choose an option: ";
    int index;
    cin >> index;
    cout << '\n';

    switch(index){
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
        list_musics_playlist(playlists);
        break;
      case 5:
        add_music_playlist(playlists,musics);
        break;
      case 6:
        remove_music_playlist(playlists,musics);
        break;
      case 7:
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

bool main_menu(List<Playlist*>& playlists, List<Music*> musics){
  cout << "IMDJ - Main Menu\n1 - Manage Musics\n2 - Manage Playlists\n" 
      "0 - Exit\nChoose an option: ";
  int index;
  cin >> index;
  cout << '\n';

  switch(index) {
    case 1:
      while(music_menu(playlists, musics));
    case 2:
      while(playlist_menu(playlists, musics));
    case 0:
      return false;
    default: 
      cout << "Invalid number!\n";
      break;
  }

  return true;
}

int main() { 
  List<Playlist*> playlists;
  List<Music*> musics;

  Playlist play1("As 100 Melhores do Samba");
  Playlist play2("Alternative Metal");
  Music mus1("O mundo é um moinho", "Cartola");
  Music mus2("Saudosa Maloca", "Adoniran Barbosa");
  Music mus3("Toxicity", "System of a Down");
  Music mus4("Aerials", "System of a Down");
  Music mus5("Dead Memories", "Slipknot");

  playlists.push_back(&play1);
  playlists.push_back(&play2);
  musics.push_back(&mus1);
  musics.push_back(&mus2);
  musics.push_back(&mus3);
  musics.push_back(&mus4);
  musics.push_back(&mus5);

  playlists.get(0)->value->add_music(&mus1);
  playlists.get(0)->value->add_music(&mus4);
  playlists.get(0)->value->add_music(&mus2);
  playlists.get(1)->value->add_music(&mus3);
  playlists.get(1)->value->add_music(&mus4);
  playlists.get(1)->value->add_music(&mus5);
  playlists.get(1)->value->add_music(&mus2);

  // User Interface.
  while(main_menu(playlists, musics));

  return 0;
}
