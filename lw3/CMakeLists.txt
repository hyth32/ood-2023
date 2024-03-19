cmake_minimum_required(VERSION 3.27)
project(lw3)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(lw3 main.cpp ${SOURCES}
        include/ShapeReader.h
        src/ShapeReader.cpp
        include/ShapeDrawer.h
        src/ShapeDrawer.cpp)

target_link_libraries(lw3 sfml-graphics sfml-audio)