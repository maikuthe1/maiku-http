cmake_minimum_required(VERSION 3.0)

project(maiku-http CXX)

OPTION (BUILD_SHARED_LIBS "Build shared libraries." ON)

include_directories( ${CMAKE_SOURCE_DIR}/src/headers )
add_subdirectory(src)
