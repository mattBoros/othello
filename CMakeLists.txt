cmake_minimum_required(VERSION 3.14)
project(othello)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Ofast -funroll-loops -mtune=native -fomit-frame-pointer")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(othello main.cpp AlphaBeta.h State.h BitSet.h Action.h Piece.h Util.h Debug.h TimerWidget.h)