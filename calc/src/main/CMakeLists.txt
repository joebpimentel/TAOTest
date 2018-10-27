message("main level CMakeLists.txt")
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "" FORCE)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_compile_options(-no-pie)

add_subdirectory(cpp)
add_subdirectory(calcserver)
add_subdirectory(calcclient)
add_subdirectory(calclib)
