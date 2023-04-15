cmake_minimum_required(VERSION 3.26)
project(projeto1 LANGUAGES CXX)
include_directories(include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
add_executable( program 
		        src/main.cpp
                src/music.cpp
                src/playlist.cpp
                src/linked_list.cpp )
