cmake_minimum_required(VERSION 3.26)
project(lab9_extra)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab9_extra main.cpp
        Account.h
        Account.cpp
        Customer.h
        Customer.cpp
        Bank.h
        Bank.cpp)
