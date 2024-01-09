cmake_minimum_required(VERSION 3.26)
project(probaKollokvium)

set(CMAKE_CXX_STANDARD 23)

add_executable(probaKollokvium main.cpp
        Animal.h
        Animal.cpp
        Dog.h
        Dog.cpp
        Cat.h
        Cat.cpp
        Base.h
        Base.cpp
        Derived.h
        Derived.cpp)
