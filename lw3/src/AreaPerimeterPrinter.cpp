#include "AreaPerimeterPrinter.h"
#include <Triangle.h>
#include <Rectangle.h>
#include <Circle.h>

AreaPerimeterPrinter::AreaPerimeterPrinter(std::ostream &out) : out(out) {}

void AreaPerimeterPrinter::visit(Triangle *triangle) {
    out << "Triangle: P=" << triangle->perimeter() << "; S=" << triangle->area() << std::endl;
}

void AreaPerimeterPrinter::visit(Rectangle *rectangle) {
    out << "Rectangle: P=" << rectangle->perimeter() << "; S=" << rectangle->area() << std::endl;
}

void AreaPerimeterPrinter::visit(Circle *circle) {
    out << "Circle: P=" << circle->perimeter() << "; S=" << circle->area() << std::endl;
}