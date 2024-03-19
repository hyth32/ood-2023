#include "visitors/ShapeVisitor.h"

class Triangle : public Shape {
public:
    Triangle(const sf::Vector2f &p1, const sf::Vector2f &p2, const sf::Vector2f &p3);

    void draw(sf::RenderWindow &window) override;

    void setColor(const sf::Color &color) override;

    void accept(ShapeVisitor *visitor) override;

    double perimeter() const override;

    double area() const override;

private:
    sf::ConvexShape triangle;

    static double dist(const sf::Vector2f &a, const sf::Vector2f &b);
};