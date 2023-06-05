// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "file.h"
#include "interface.h"

int main(int argc, char const* argv[]) {
  List<Playlist*> playlists;
  List<Music*> musics;

  string filename{argv[1]};

  if (argc > 1) {
    fstream file(filename);
    read_file(playlists, musics, file);
  }

  // User Interface.
  while (main_menu(playlists, musics)) {
  }

  if (argc > 1) {
    fstream file(filename, std::ios::trunc | std::ios::out);
    write_file(playlists, file);
  }

  // List::add(List<T>& list)
  /* List<Music*> musics2;
  auto test_music = new Music("Oi", "Tchau");
  musics2.push_back(test_music);
  musics.add(musics2);
  musics.print(); */

  // List::remove(initializer_list<T> list)
  /* musics.print();
  cout << '\n';
  musics.remove({mus1, mus2, mus5});
  musics.print(); */

  // List::List(List<T>& list)
  /* List<Playlist*> playlists2(playlists);
  playlists2.print(); */

  // List::operator+(List<T>& list_b);
  /* List<Playlist*> playlists2;
  auto play3 = new Playlist("Banana");
  playlists2.push_back(play3);
  List<Playlist*> playlists3(playlists + playlists2);
  playlists3.print(); */

  // List::operator>>(Node<T>*)
  /* auto music = new Music("Teste", "Testando");
  auto node = new Node<Music*>(music);
  musics.print();
  cout << '\n';
  musics >> node;
  musics.print();
  cout << '\n' << node->value;
  delete music;
  delete node; */

  // List::operator<<(Node<T>*)
  /* auto play3 = new Playlist("Oi");
  auto node = new Node<Playlist*>(play3);
  playlists << node;
  playlists.print(); */

  // Playlist::add_music(Playlist&)
  /*
  play1->print();
  cout << "\n";
  play1->add_music(*play2);
  play1->print();
  */

  // Playlist::remove_music(Playlist&)
  /*
    play1->print();
    play1->remove_music(*play2);
    cout << "\n";
    play1->print();
  */

  // Playlist(Playlist&)
  /*
    auto play3 = new Playlist(*play1);
    play3->print();
  */

  // Playlist::operator+(Playlist*)
  /* playlists[0]->print();
  playlists[1]->print();
  cout << "\n";
  Playlist play3(*playlists[0] + playlists[1]);
  play3.print(); */

  // Playlist::operator+(Music*)
  /* Playlist play3("Celular");
  Music mus6("Banana", "Pizza");
  Playlist play4(play3 + &mus6);
  play4.print(); */

  // Playlist::operator-(Playlist* playlist_b)
  /* play1->print();
  cout << '\n';
  play2->print();
  cout << '\n';
  Playlist play3(*play1 - play2);
  play3.print(); */

  // Playlist::operator-(Music* music)
  /* play1->print();
  cout << '\n' << mus2 << "\n\n";
  Playlist play3(*play1 - mus2);
  play3.print(); */

  // Playlist::operator>>(Music* music)
  /* auto test_music = new Music();
  play1->print();
  *play1 >> test_music;
  cout << test_music << '\n';
  play1->print(); */

  // Playlist::operator<<(Music* music);
  /* auto test_music = new Music("Oi", "Tchau");
  play1->print();
  *play1 << test_music;
  cout << '\n';
  play1->print(); */

  playlists.clear_nodes();
  musics.clear_nodes();

  return 0;
}
