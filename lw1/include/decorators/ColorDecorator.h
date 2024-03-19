#include "shapes/Shape.h"

class ColorDecorator : public Shape {
public:
    ColorDecorator(Shape *shape, sf::Color color);

    void draw(sf::RenderWindow &window) override;

    [[nodiscard]] double perimeter() const override;

    [[nodiscard]] double area() const override;

    void setColor(const sf::Color &newColor) override;

private:
    Shape *shape;
    sf::Color color;
};