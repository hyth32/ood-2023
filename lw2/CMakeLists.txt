cmake_minimum_required(VERSION 3.27)
project(lw2)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories(include)

file(GLOB SOURCES "src/*/*.cpp")

add_executable(lw2 main.cpp ${SOURCES}
        include/shapes/Circle.h
        include/shapes/Rectangle.h
        include/shapes/Shape.h
        include/shapes/Triangle.h
        src/shapes/Circle.cpp
        src/shapes/Rectangle.cpp
        src/shapes/Triangle.cpp
        include/singletons/CircleCreator.h
        include/singletons/RectangleCreator.h
        include/singletons/TriangleCreator.h
        src/singletons/CircleCreator.cpp
        src/singletons/RectangleCreator.cpp
        src/singletons/TriangleCreator.cpp
        include/decorators/ColorDecorator.h
        src/decorators/ColorDecorator.cpp
        include/main/ShapeDrawer.h
        include/main/ShapeReader.h
        src/main/ShapeDrawer.cpp
        src/main/ShapeReader.cpp)

target_link_libraries(lw2 sfml-graphics sfml-audio)