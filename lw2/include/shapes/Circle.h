#include "shapes/Shape.h"

class Circle : public Shape {
public:
    Circle(const sf::Vector2f &center, float radius);

    void draw(sf::RenderWindow &window) override;

    void setColor(const sf::Color &color) override;

    double perimeter() const override;

    double area() const override;

private:
    sf::CircleShape circle;
};