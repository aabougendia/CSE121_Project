


cmake_minimum_required(VERSION 3.24)
project(CSE121_Project C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

set(CMAKE_C_STANDARD 99)

add_executable(CSE121_Project game.c play.h learn.h binary_tree.h)
target_link_libraries(CSE121_Project ${GTK3_LIBRARIES})
