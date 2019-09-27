cmake_minimum_required(VERSION 3.14)
project(ega5)

set(CMAKE_CXX_STANDARD 17)

add_executable(ega5 main.cpp MC.cpp MC.h HCD.cpp HCD.h HCW.cpp HCW.h)