# SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
#
# SPDX-License-Identifier: MIT-0

cmake_minimum_required(VERSION 3.26)
project(IMDJ LANGUAGES CXX)
include_directories(include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
add_executable(program 
                src/main.cpp
                src/music.cpp
                src/playlist.cpp
                src/linked_list.cpp)
