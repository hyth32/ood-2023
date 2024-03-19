#include "main/ShapeReader.h"
#include "decorators/ColorDecorator.h"
#include "shapes/Circle.h"
#include "shapes/Rectangle.h"
#include "shapes/Triangle.h"
#include <sstream>

std::vector<std::unique_ptr<Shape>> ShapeReader::readShapesFromFile(const std::string &filename) {
    std::ifstream input(filename);
    if (!input) {
        throw std::runtime_error("Error: Could not open file " + filename);
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;
        if (type == "TRIANGLE:") {
            sf::Vector2f p1, p2, p3;
            char ch;
            iss >> ch >> ch >> ch >> p1.x >> ch >> p1.y >> ch >> ch >> ch >> ch >> p2.x >> ch >> p2.y >> ch >> ch >> ch >> ch >> p3.x >> ch >> p3.y;
            auto triangle = new Triangle(p1, p2, p3);
            auto coloredTriangle = std::make_unique<ColorDecorator>(triangle, sf::Color::Red);
            shapes.push_back(std::move(coloredTriangle));
        } else if (type == "RECTANGLE:") {
            sf::Vector2f p1, p2;
            char ch;
            iss >> ch >> ch >> ch >> p1.x >> ch >> p1.y >> ch >> ch >> ch >> ch >> p2.x >> ch >> p2.y;
            auto rectangle = new Rectangle(p1, p2);
            auto coloredRectangle = std::make_unique<ColorDecorator>(rectangle, sf::Color::Green);
            shapes.push_back(std::move(coloredRectangle));
        } else if (type == "CIRCLE:") {
            sf::Vector2f center;
            float radius;
            char ch;
            iss >> ch >> ch >> center.x >> ch >> center.y >> ch >> ch >> ch >> radius;
            auto circle = new Circle(center, radius);
            auto coloredCircle = std::make_unique<ColorDecorator>(circle, sf::Color::Blue);
            shapes.push_back(std::move(coloredCircle));
        }
    }

    return shapes;
}
