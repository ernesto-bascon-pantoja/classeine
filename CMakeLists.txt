cmake_minimum_required(VERSION 3.17)

project(classeinecore)

set(CMAKE_CXX_STANDARD 20)

add_library(classeinecore SHARED code/inc/classeine/core/string_tools.h code/src/classeine/core/string_tools.cpp code/inc/classeine/core/configuration.h code/src/classeine/core/configuration.cpp code/inc/classeine/core/log_level.h code/src/classeine/core/log_level.cpp code/inc/classeine/core/logger.h code/inc/classeine/core/log_console_output.h code/src/classeine/core/log_console_output.cpp code/inc/classeine/core/log_writer.h)

target_include_directories(classeinecore PRIVATE code/inc)


