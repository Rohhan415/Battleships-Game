
cmake_minimum_required(VERSION 3.20)
project(Projekt)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projekt main.cpp Player.cpp Player.h Ship.cpp Ship.h Board.cpp Board.h Constants.h Game.cpp Game.h Enums.h)
