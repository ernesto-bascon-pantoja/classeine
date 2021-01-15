cmake_minimum_required(VERSION 3.17)

project(classeinecore)

set(CMAKE_CXX_STANDARD 20)

add_library(classeinecore SHARED src/classeine/core/string_tools.h src/classeine/core/string_tools.cpp)

target_include_directories(classeinecore PRIVATE ${CMAKE_SOURCE_DIR})


