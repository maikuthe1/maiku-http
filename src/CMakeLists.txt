cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
# set(CMAKE_BUILD_DIR ${PROJECT_SOURCE_DIR}/build)

set(maiku-http_LIB
    maiku-http-server.cpp
)

set(maiku-http_INCLUDES
    headers/maiku-http-server.hpp
    headers/maiku-http-header.hpp
    headers/maiku-http-request.hpp
    headers/maiku-http-response.hpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -shared")

add_library(maiku-http SHARED ${maiku-http_LIB})

install(TARGETS maiku-http DESTINATION /usr/lib)
install(FILES ${maiku-http_INCLUDES} DESTINATION /usr/include/maiku-http-lib)
