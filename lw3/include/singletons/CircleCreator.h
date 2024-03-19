#include "shapes/Circle.h"

class CircleCreator {
public:
    static CircleCreator &getInstance();

    Circle *create(const sf::Vector2f &center, float radius);

    CircleCreator(CircleCreator const &) = delete;

    void operator=(CircleCreator const &) = delete;

private:
    CircleCreator();
};