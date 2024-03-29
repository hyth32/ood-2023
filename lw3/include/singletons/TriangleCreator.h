#include "shapes/Triangle.h"

class TriangleCreator {
public:
    static TriangleCreator &getInstance();

    Triangle *create(const sf::Vector2f &p1, const sf::Vector2f &p2, const sf::Vector2f &p3);

    TriangleCreator(TriangleCreator const &) = delete;

    void operator=(TriangleCreator const &) = delete;

private:
    TriangleCreator();
};