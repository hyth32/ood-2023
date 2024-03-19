#include "decorators/ColorDecorator.h"
#include "visitors/AreaPerimeterPrinter.h"
#include "main/ShapeReader.h"
#include "main/ShapeDrawer.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    std::ofstream output("output.txt");

    std::vector<std::unique_ptr<Shape>> shapes;
    try {
        shapes = ShapeReader::readShapesFromFile(argv[1]);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes");
    ShapeDrawer::drawShapes(window, shapes);

    AreaPerimeterPrinter printer(output);
    for (auto& shape: shapes) {
        shape->accept(&printer);
    }

    return 0;
}