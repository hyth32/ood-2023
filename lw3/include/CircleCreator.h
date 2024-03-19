#include "Circle.h"

class CircleCreator {
public:
    static CircleCreator &getInstance();

    Circle *create(const sf::Vector2f &center, float radius);

private:
    CircleCreator();

    CircleCreator(CircleCreator const &) = delete;

    void operator=(CircleCreator const &) = delete;
};