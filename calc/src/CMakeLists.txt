project(calc)
cmake_minimum_required(VERSION 2.8)
SET( CMAKE_VERBOSE_MAKEFILE off )
message("Top level CMakeLists.txt")
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(main)
