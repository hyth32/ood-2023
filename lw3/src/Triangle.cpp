#include "../include/Triangle.h"
#include <cmath>

Triangle::Triangle(const sf::Vector2f &p1, const sf::Vector2f &p2, const sf::Vector2f &p3)
        : triangle(3) {
    triangle.setPoint(0, p1);
    triangle.setPoint(1, p2);
    triangle.setPoint(2, p3);
}

void Triangle::draw(sf::RenderWindow &window) {
    window.draw(triangle);
}

void Triangle::setColor(const sf::Color &color) {
    triangle.setFillColor(color);
}

void Triangle::accept(ShapeVisitor *visitor) {
    visitor->visit(this);
}

double Triangle::perimeter() const {
    return dist(triangle.getPoint(0), triangle.getPoint(1)) +
           dist(triangle.getPoint(1), triangle.getPoint(2)) +
           dist(triangle.getPoint(2), triangle.getPoint(0));
}

double Triangle::area() const {
    double p = perimeter() / 2;
    return sqrt(p * (p - dist(triangle.getPoint(0), triangle.getPoint(1))) *
                (p - dist(triangle.getPoint(1), triangle.getPoint(2))) *
                (p - dist(triangle.getPoint(2), triangle.getPoint(0))));
}

double Triangle::dist(const sf::Vector2f &a, const sf::Vector2f &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}