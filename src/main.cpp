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

  // Pointer for usage with Playlist::next_music().
  Music* to_play;

  // Indexes for User Input.
  int user_index{0};
  char confirmation{'\0'};

  // User Interface.
  while(loop0){
    cout << "IMDJ - Main Menu\n1 - Manage Musics\n2 - Manage Playlists\n" 
        "0 - Exit\nChoose an option: ";
    cin >> index0;

    switch(index0) {
      case 1:
        loop1 = true;
        while(loop1){
          cout << "IMDJ - Musics Menu\n1 - Register Music\n"
            "2 - Remove Music\n3 - List Musics\n0 - Return\n"
            "Choose an option: ";
          cin >> index1;

          switch(index1){
            case 1:
              cout << "What is the title of the Music? ";
              cin.ignore();
              getline(cin, title);
              cout << "What is the artist of the Music? ";
              getline(cin, artist);
              musics.push_back(new_music(title, artist)); 
              break;
            case 2:
              cout << "What is the index of the Music to remove? ";
              cin >> user_index;
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
                cout << "List of Musics:\n";
                musics.print();
              }
              break;
            case 0:
              loop1 = false;
              break;
            default:
              cout << "Invalid number!\n";
              break;
          }
        }
        break;
      case 2:
        loop2 = true; 
        while(loop2){
          cout << "IMDJ - Playlists Menu\n1 - Create Playlist\n"
            "2 - Delete Playlist\n3 - List Playlists\n4 - List Musics from a Playlist"
            "\n5 - Add Music to a Playlist\n6 - Remove Music from a Playlist\n"
            "7 - Move Music from a Playlist\n"
            "8 - Show next Music to play in a Playlist\n0 - Return\n"
            "Choose an option: ";
          cin >> index2;

          switch(index2){
            case 1:
              cout << "What is the name of the Playlist? ";
              cin.ignore();
              getline(cin, name);
              playlists.push_back(new_playlist(name)); 
              break;
            case 2:
              cout << "What is the index of the Playlist to remove? ";
              cin >> user_index;
              if(user_index < 1 or user_index > playlists.getSize()){
                cout << "Invalid index!\n";
              } else {
                --user_index;
                cout << "This will remove Playlist:\n" << playlists.get(user_index)->value->getName() <<
                  "\nAre you sure [y/n]? ";
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
              break;
            case 3:
              if(playlists.getSize() == 0){
                cout << "No Playlist on the system!\n";
              } else {
                cout << "List of Playlists:\n";
                playlists.print();
              }
              break;
            case 4:
              cout << "What is the index of the Playlist you want? ";
              cin >> user_index;
              if(user_index < 1 or user_index > playlists.getSize()){
                cout << "Invalid index!\n";
              } else {
                --user_index;
                playlists.get(user_index)->value->print(); 
              }
              break;
            case 5:
              break;
            case 6:
              break;
            case 7:
              break;
            case 8:
              cout << "What is the index of the Playlist you want? ";
              cin >> user_index;
              if(user_index < 1 or user_index > playlists.getSize()){
                cout << "Invalid index!\n";
              } else {
                --user_index;
                to_play = playlists.get(user_index)->value->next_music();
                if(to_play == nullptr){
                  cout << "No Musics on this queue.\n";
                } else {
                  cout << "#" << playlists.get(user_index)->value->getQueue() << " On Queue:\n";
                  cout << to_play; 
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
        break;
      case 0:
        loop0 = false;
        break;
      default: 
        cout << "Invalid number!\n";
        break;
    }
  }

  return 0;
}
