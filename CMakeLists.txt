cmake_minimum_required(VERSION 3.17)

project(classeinecore)

set(CMAKE_CXX_STANDARD 20)

add_library(classeinecore SHARED code/inc/classeine/core/string_tools.h code/src/classeine/core/string_tools.cpp)

target_include_directories(classeinecore PRIVATE code/inc)


