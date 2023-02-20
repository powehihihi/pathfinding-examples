
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Werror")
project( a.out )
add_executable( a.out 
  src/main.cpp
  src/dijkstra.cpp
  src/graph.h
  src/graph.cpp
  src/astar.cpp
  )
