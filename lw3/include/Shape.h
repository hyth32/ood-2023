#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>

class ShapeVisitor;

class Triangle;

class Rectangle;

class Circle;

class Shape {
public:
    virtual ~Shape() = default;

    virtual void draw(sf::RenderWindow &window) = 0;

    [[nodiscard]] virtual double perimeter() const = 0;

    [[nodiscard]] virtual double area() const = 0;

    virtual void setColor(const sf::Color &color) = 0;

    virtual void accept(ShapeVisitor *visitor) = 0;
};

#endif // SHAPE_H