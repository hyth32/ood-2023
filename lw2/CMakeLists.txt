cmake_minimum_required(VERSION 3.27)
project(lw2)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories(include)

file(GLOB SOURCES "src/*/*.cpp")

add_executable(lw2 main.cpp ${SOURCES})

target_link_libraries(lw2 sfml-graphics sfml-audio)