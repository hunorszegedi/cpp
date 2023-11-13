cmake_minimum_required(VERSION 3.26)
project(parcialis_minta)

set(CMAKE_CXX_STANDARD 23)

add_executable(parcialis_minta main.cpp
        Book.h
        Book.cpp
        Library.h
        Library.cpp
        Playlist.h
        Playlist.cpp
        Video.h
        Video.cpp)
