cmake_minimum_required(VERSION 3.27)
project(lw1)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(lw1 main.cpp)

target_link_libraries(lw1 sfml-graphics sfml-audio)