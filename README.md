<!--
SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome

SPDX-License-Identifier: MIT-0
-->

# IMDJ
IMDJ is a symbolic CLI music library manager made for the second Project of the course LP1, from BTI-UFRN. 

## Instalation

### Requirements
- C++ compiler on your PATH
- CMake
- Git (optional)
- Doxygen (optional)
- Graphviz (optional, for documentation graphics)

### Compilation
``` 
git clone https://github.com/Stargazer3240/lp1-projeto2.git
cd ./lp1-projeto2
cmake -S . -B build/
cmake --build build/
```

## Usage
### Starting the program
After compiling the code, run `./bin/program` on the root directory.

### Documentation
If you have installed Doxygen, run `doxygen` on the root directory. Then open
`./docs/html/index.html` with a modern browser.

### User Interface
When you run the program, you'll be faced with a fairly intuitive Command Line 
Interface. To navigate in the menus, you'll have to digit your desired number
from the list and press enter. Example:
```
IMDJ - Main Menu
1 - Manage Musics
2 - Manage Playlists
0 - Exit
Choose an option: 1

IMDJ - Musics Menu
1 - Register Music
2 - Remove Music
3 - List Musics
0 - Return
Choose an option: 0

IMDJ - Main Menu
1 - Manage Musics
2 - Manage Playlists
0 - Exit
Choose an option: 2

IMDJ - Playlists Menu
1 - Create Playlist
2 - Delete Playlist
3 - List Playlists
4 - List Musics from a Playlist
5 - Add Music to a Playlist
6 - Remove Music from a Playlist
7 - Move Music from a Playlist
8 - Show next Music to play in a Playlist
0 - Return
Choose an option: 0

IMDJ - Main Menu
1 - Manage Musics
2 - Manage Playlists
0 - Exit
Choose an option: 0
```
Most of the navigation occurs in the mentioned way but, in some cases, you will be asked
to type a name, where you can enter multiple words. Also, in the second Playlist menu page,
some operations ask for two indexes, where you should type them separed by space (i.e `4 5`).

## Limitations
- If you type a non-numeric char when the program says "Choose an option: ", it will break and enter an infinite loop.

## Author
- Fabrício Moura Jácome

## License
This project is licensed under the [MIT License](https://spdx.org/licenses/MIT.html) (C++ source files) and [MIT-0 License](https://spdx.org/licenses/MIT-0) (documentation and configuration files) - see the LICENSE folder for details.
