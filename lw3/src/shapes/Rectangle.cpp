#include "shapes/Rectangle.h"

Rectangle::Rectangle(const sf::Vector2f &p1, const sf::Vector2f &p2)
        : rectangle(sf::Vector2f(std::abs(p1.x - p2.x), std::abs(p1.y - p2.y))) {
    rectangle.setPosition(std::min(p1.x, p2.x), std::min(p1.y, p2.y));
}

void Rectangle::draw(sf::RenderWindow &window) {
    window.draw(rectangle);
}

void Rectangle::setColor(const sf::Color &color) {
    rectangle.setFillColor(color);
}

void Rectangle::accept(ShapeVisitor *visitor) {
    visitor->visit(this);
}

double Rectangle::perimeter() const {
    return 2 * (rectangle.getSize().x + rectangle.getSize().y);
}

double Rectangle::area() const {
    return rectangle.getSize().x * rectangle.getSize().y;
}