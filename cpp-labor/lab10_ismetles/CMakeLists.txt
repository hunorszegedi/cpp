cmake_minimum_required(VERSION 3.26)
project(lab10_ismetles)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab10_ismetles main.cpp
        Person.h
        Person.cpp
        Employee.h
        Employee.cpp
        Manager.h
        Manager.cpp)
