#include "visitors/ShapeVisitor.h"

class Rectangle : public Shape {
public:
    Rectangle(const sf::Vector2f &p1, const sf::Vector2f &p2);

    void draw(sf::RenderWindow &window) override;

    void setColor(const sf::Color &color) override;

    void accept(ShapeVisitor *visitor) override;

    double perimeter() const override;

    double area() const override;

private:
    sf::RectangleShape rectangle;
};