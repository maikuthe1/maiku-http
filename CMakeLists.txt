cmake_minimum_required(VERSION 3.0)

project(maiku-http)

add_executable(maiku-http main.cpp)

install(TARGETS maiku-http RUNTIME DESTINATION bin)
