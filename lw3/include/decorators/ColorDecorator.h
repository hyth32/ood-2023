#include "shapes/Shape.h"

class ColorDecorator : public Shape {
public:
    ColorDecorator(Shape *shape, sf::Color color);

    void draw(sf::RenderWindow &window) override;

    double perimeter() const override;

    double area() const override;

    void setColor(const sf::Color &color) override;

    void accept(ShapeVisitor *visitor) override;

private:
    Shape *shape;
    sf::Color color;
};