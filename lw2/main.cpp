#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

#include "main/ShapeReader.h"
#include "main/ShapeDrawer.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    std::ofstream output("output.txt");

    std::vector<std::unique_ptr<Shape>> shapes;
    try {
        shapes = ShapeReader::readShapesFromFile(argv[1]);
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes");
    ShapeDrawer::drawShapes(window, shapes);

    for (auto &shape: shapes) {
        output << "P=" << shape->perimeter() << "; S=" << shape->area() << std::endl;
    }

    return 0;
}