#include "decorators/ColorDecorator.h"

ColorDecorator::ColorDecorator(Shape *shape, sf::Color color)
        : shape(shape), color(color) {}

void ColorDecorator::draw(sf::RenderWindow &window) {
    shape->setColor(color);
    shape->draw(window);
}

double ColorDecorator::perimeter() const {
    return shape->perimeter();
}

double ColorDecorator::area() const {
    return shape->area();
}

void ColorDecorator::setColor(const sf::Color &newColor) {
    this->color = newColor;
}

void ColorDecorator::accept(ShapeVisitor *visitor) {
    shape->accept(visitor);
}