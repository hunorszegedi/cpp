cmake_minimum_required(VERSION 3.26)
project(labor12_ismetles)

set(CMAKE_CXX_STANDARD 23)

add_executable(labor12_ismetles main.cpp
        Settlement.h
        Settlement.cpp
        SettlementsStatistics.h
        SettlementsStatistics.cpp
        SettlementStatisticsImpl.h
        SettlementStatisticsImpl.cpp)
