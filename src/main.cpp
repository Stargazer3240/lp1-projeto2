// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "playlist.h"

using std::cin, std::getline;

bool music_menu(List<Music*>& musics){ 
    cout << "IMDJ - Musics Menu\n1 - Register Music\n"
      "2 - Remove Music\n3 - List Musics\n0 - Return\n"
      "Choose an option: ";
    cin >> index1;
    cout << '\n';

    switch(index1){
      case 1:
        cout << "What is the title of the Music? ";
        cin.ignore();
        getline(cin, title);
        cout << "What is the artist of the Music? ";
        getline(cin, artist);
        musics.push_back(new_music(title, artist)); 
        cout << "Music added with success!\n";
        break;
      case 2:
        cout << "What is the index of the Music to remove? ";
        cin >> user_index;
        cout << '\n';
        if(user_index < 1 or user_index > musics.getSize()){
          cout << "Invalid index!\n";
        } else {
          --user_index;
          cout << "This will remove Music:\n" << musics.get(user_index)->value <<
            "Are you sure [y/n]? ";
          cin >> confirmation;
          if(confirmation == 'y') {
            musics.remove(user_index);
            cout << "Music removed!\n";
          } else if(confirmation == 'n') {
            cout << "Operation cancelled.\n";
          } else {
            cout << "Invalid operation.\n";
          }
        }
        break;
      case 3:
        if(musics.getSize() == 0){
          cout << "No Music on the system!\n";
        } else {
          cout << "\nList of Musics:\n";
          musics.print();
          cout << '\n';
        }
        break;
      case 0:
        return false;
      default:
        cout << "Invalid number!\n";
        break;
    }
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

  int user_index;
  cin >> user_index;

  cout << '\n';

  if(user_index < 1 or user_index > playlists.getSize()){
    cout << "Invalid index!\n";
  } else {
    --user_index;

    cout << "This will remove Playlist:\n" << playlists.get(user_index)->value->getName() <<
      "\nAre you sure [y/n]? ";

    char confirmation;
    cin >> confirmation;

    if(confirmation == 'y') {
      playlists.remove(user_index);
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

void list_music_playlists(List<Playlist*>& playlists) {

}

bool playlist_menu(List<Music*>& musics, List<Playlist*>& playlists){
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
        cout << "What is the index of the Playlist you want? ";
        cin >> user_index;
        cout << '\n';
        if(user_index < 1 or user_index > playlists.getSize()){
          cout << "Invalid index!\n";
        } else {
          --user_index;
          playlists.get(user_index)->value->print(); 
          cout << '\n';
        }
        break;
      case 5:
        cout << "What is the index of the Playlist you want? ";
        cin >> user_index;
        cout << '\n';
        if(user_index < 1 or user_index > playlists.getSize()){
          cout << "Invalid index!\n";
        } else {
          --user_index;
          temp_index = user_index;
          if(musics.getSize() == 0){
            cout << "No Music on the system!\n";
          } else {
            cout << "\nList of Musics:\n";
            musics.print();
            cout << '\n';
            cout << "What is the index of the Music you want to add? ";
            cin >> user_index;
            
            if(user_index < 1 or user_index > musics.getSize()){
              cout << "Invalid index!\n";
            } else {
              temp_music = musics.get(user_index)->value;
              playlists.get(temp_index)->value->add_music(temp_music);
              cout << "Music added to playlist with success.\n";
            }
          }
        }
        break;
      case 6:
        cout << "What is the index of the Playlist you want? ";
        cin >> user_index;
        cout << '\n';
        if(user_index < 1 or user_index > playlists.getSize()){
          cout << "Invalid index!\n";
        } else {
          --user_index;
          temp_index = user_index;
          if(musics.getSize() == 0){
            cout << "No Music on the system!\n";
          } else {
            playlists.get(user_index)->value->print(); 
            cout << '\n';
            cout << "What is the index of the Music you want to add? ";
            cin >> user_index;
            
            if(user_index < 1 or user_index > musics.getSize()){
              cout << "Invalid index!\n";
            } else {
              playlists.get(temp_index)->value->remove_music(user_index);
              cout << "Music removed from playlist with success.\n";
            }
          }
        }
        break;
      case 7:
        break;
      case 8:
        cout << "What is the index of the Playlist you want? ";
        cin >> user_index;
        cout << '\n';
        if(user_index < 1 or user_index > playlists.getSize()){
          cout << "Invalid index!\n";
        } else {
          --user_index;
          temp_music = playlists.get(user_index)->value->next_music();
          if(temp_music == nullptr){
            cout << "No Musics on this queue.\n";
          } else {
            cout << "\n#" << playlists.get(user_index)->value->getQueue() << " On Queue:\n";
            cout << temp_music; 
          }
        }
        break;
      case 0:
        loop2 = false;
        break;
      default:
        cout << "Invalid number!\n";
        break;
    }
  }

  return true;
}

bool main_menu(){
  cout << "IMDJ - Main Menu\n1 - Manage Musics\n2 - Manage Playlists\n" 
      "0 - Exit\nChoose an option: ";
  cin >> index;
  cout << '\n';

  switch(index) {
    case 1:
      while(music_menu);
    case 2:
      while(loop2){
    case 0:
      loop0 = false;
      break;
    default: 
      cout << "Invalid number!\n";
      break;
  }
}

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

  // Test condition of each while.
  bool loop0{true};
  bool loop1{true};
  bool loop2{true};

  // Switch index for each loop.
  int index0{0};
  int index1{0};
  int index2{0};

  // Placeholders for classes attributes.
  string title;
  string artist;
  string name;

  // Placeholder for Music pointer.
  Music* temp_music;

  // Indexes for User Input.
  int user_index{0};
  int temp_index{0};
  char confirmation{'\0'};

  // User Interface.
  while(main_menu);

  return 0;
}
