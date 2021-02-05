cmake_minimum_required(VERSION 3.17)

project(classeinecore)

set(CMAKE_CXX_STANDARD 20)

add_library(classeinecore SHARED code/inc/classeine/core/string_tools.h code/src/classeine/core/string_tools.cpp code/inc/classeine/core/configuration.h code/src/classeine/core/configuration.cpp code/inc/classeine/core/log_level.h code/src/classeine/core/log_level.cpp code/inc/classeine/core/log_console_output.h code/src/classeine/core/log_console_output.cpp code/inc/classeine/core/log_writer.h code/inc/classeine/core/CLogOutput.h code/inc/classeine/core/unique_object.h code/inc/classeine/net/rest_server.h code/inc/classeine/core/logger.h code/inc/classeine/core/CDomain.h code/inc/classeine/core/domain.h code/inc/classeine/core/entity.h code/inc/classeine/net/civetweb_utils.h code/inc/classeine/net/http_request.h code/src/classeine/net/http_request.cpp code/src/classeine/net/civetweb_utils.cpp)

target_include_directories(classeinecore PRIVATE code/inc)
target_include_directories(classeinecore PRIVATE ../../civetweb/include)
target_include_directories(classeinecore PRIVATE ../civetweb/include)

target_link_directories(classeinecore PRIVATE ${CMAKE_SOURCE_DIR}/../classeine/cmake-build-debug)
