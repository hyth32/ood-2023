#include "Circle.h"
#include <cmath>

Circle::Circle(const sf::Vector2f &center, float radius)
        : circle(radius) {
    circle.setPosition(center);
}

void Circle::draw(sf::RenderWindow &window) {
    window.draw(circle);
}

void Circle::setColor(const sf::Color &color) {
    circle.setFillColor(color);
}

void Circle::accept(ShapeVisitor *visitor) {
    visitor->visit(this);
}

double Circle::perimeter() const {
    return 2 * M_PI * circle.getRadius();
}

double Circle::area() const {
    return M_PI * pow(circle.getRadius(), 2);
}