// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "file.h"
#include "interface.h"
#include "playlist.h"

int main(int argc, char const* argv[]) {
  List<Playlist*> playlists;
  List<Music*> musics;

  if (argc > 1) {
    string filename{argv[1]};
    fstream file(filename);
    read_file(playlists, musics, file);
  }

  // User Interface.
  while (main_menu(playlists, musics)) {
  }

  if (argc > 1) {
    string filename{argv[1]};
    fstream file(filename, std::ios::trunc | std::ios::out);
    write_file(playlists, file);
  }

  // List::add(List<T>& list)
  // List<Music*> musics2;
  // auto test_music = new Music("Oi", "Tchau");
  // musics2.push_back(test_music);
  // musics.add(musics2);
  // musics.print();

  // List::remove(initializer_list<T> list)
  // auto new_music1 = new Music("M1", "A1");
  // auto new_music2 = new Music("M2", "A2");
  // musics.push_back(new_music1);
  // musics.push_back(new_music2);
  // musics.print();
  // cout << '\n';
  // musics.remove({new_music1, new_music2});
  // musics.print();

  // List::List(List<T>& list)
  // List<Playlist*> playlists2(playlists);
  // playlists2.print();

  // List::operator+(List<T>& list_b);
  // List<Playlist*> playlists2;
  // auto play2 = new Playlist("Banana");
  // playlists2.push_back(play2);
  // List<Playlist*> playlists3(playlists + playlists2);
  // playlists3.print();

  // List::operator>>(Node<T>*)
  // auto music = new Music("Teste", "Testando");
  // auto node = new Node<Music*>(music);
  // musics.print();
  // cout << '\n';
  // musics >> node;
  // musics.print();
  // cout << '\n' << node->value;

  // List::operator<<(Node<T>*)
  // auto play3 = new Playlist("Oi");
  // auto node = new Node<Playlist*>(play3);
  // playlists << node;
  // playlists.print();

  // Playlist::add_music(Playlist&)
  // auto play1 = new Playlist("Play1");
  // auto play2 = new Playlist("Play2");
  // auto mus1 = new Music("M1", "A1");
  // auto mus2 = new Music("M2", "A2");
  // play2->add_music(mus1);
  // play2->add_music(mus2);
  // play1->add_music(*play2);
  // play1->print();

  // Playlist::remove_music(Playlist&)
  // auto play1 = new Playlist("Play1");
  // auto play2 = new Playlist("Play2");
  // auto mus1 = new Music("M1", "A1");
  // auto mus2 = new Music("M2", "A2");
  // play1->add_music(mus1);
  // play1->add_music(mus2);
  // play2->add_music(mus1);
  // play2->add_music(mus2);
  // play1->print();
  // play1->remove_music(*play2);
  // cout << "\n";
  // play1->print();

  // Playlist(Playlist&)
  // auto play1 = new Playlist("Play1");
  // auto mus1 = new Music("M1", "A1");
  // auto mus2 = new Music("M2", "A2");
  // play1->add_music(mus1);
  // play1->add_music(mus2);
  // auto play2 = new Playlist(*play1);
  // play2->print();

  // Playlist::operator+(Playlist*)
  // auto play1 = new Playlist("Play1");
  // auto play2 = new Playlist("Play2");
  // auto mus1 = new Music("M1", "A1");
  // auto mus2 = new Music("M2", "A2");
  // play1->add_music(mus1);
  // play1->add_music(mus2);
  // play2->add_music(mus1);
  // play2->add_music(mus2);
  // Playlist play3(*play1 + play2);
  // play3.print();

  // Playlist::operator+(Music*)
  // Playlist play1("Celular");
  // Music mus1("Banana", "Pizza");
  // Playlist play2(play1 + &mus1);
  // play2.print();

  // Playlist::operator-(Playlist* playlist_b)
  // auto play1 = new Playlist("Play1");
  // auto play2 = new Playlist("Play2");
  // auto mus1 = new Music("M1", "A1");
  // auto mus2 = new Music("M2", "A2");
  // play1->add_music(mus1);
  // play1->add_music(mus2);
  // play2->add_music(mus1);
  // Playlist play3(*play1 - play2);
  // play3.print();

  // Playlist::operator-(Music* music)
  // auto play1 = new Playlist("Play1");
  // auto mus1 = new Music("M1", "A1");
  // auto mus2 = new Music("M2", "A2");
  // play1->add_music(mus1);
  // play1->add_music(mus2);
  // Playlist play2(*play1 - mus2);
  // play2.print();

  // Playlist::operator>>(Music* music)
  // auto play1 = new Playlist("Play1");
  // auto mus1 = new Music("M1", "A1");
  // play1->add_music(mus1);
  // auto test_music = new Music();
  // *play1 >> test_music;
  // cout << test_music << '\n';
  // play1->print();

  // Playlist::operator<<(Music* music);
  // auto play1 = new Playlist("Play1");
  // auto mus1 = new Music("M1", "A1");
  // *play1 << mus1;
  // play1->print();

  playlists.clear_nodes();
  musics.clear_nodes();

  return 0;
}
