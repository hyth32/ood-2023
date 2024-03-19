#include "singletons/CircleCreator.h"

CircleCreator &CircleCreator::getInstance() {
    static CircleCreator instance;
    return instance;
}

Circle *CircleCreator::create(const sf::Vector2f &center, float radius) {
    return new Circle(center, radius);
}

CircleCreator::CircleCreator() {}