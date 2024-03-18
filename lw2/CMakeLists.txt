cmake_minimum_required(VERSION 3.27)
project(lw2)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(lw2 main.cpp)

target_link_libraries(lw2 sfml-graphics sfml-audio)