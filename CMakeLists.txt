# SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
#
# SPDX-License-Identifier: MIT-0

cmake_minimum_required(VERSION 3.26)
project(IMDJ LANGUAGES CXX)

include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS=ON)

add_executable(program 
                src/main.cpp
                src/music.cpp
                src/playlist.cpp
                src/linked_list.cpp)


if (MSVC)
    # warning level 4
    add_compile_options(/W4 /WX)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic -Werror -pedantic-errors -Weffc++ -Wsign-conversion)
    if(CMAKE_BUILD_TYPE STREQUAL Debug)
        add_compile_options(-glldb)
    endif()
endif()

find_program(CLANG_TIDY clang-tidy)
if(CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY})
endif()

find_program(CLANG_COMPILER clang)
if(CLANG_COMPILER)
    set(CMAKE_CXX_COMPILER ${CLANG_COMPILER})
endif()
