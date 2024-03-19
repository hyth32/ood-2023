#include "singletons/TriangleCreator.h"

TriangleCreator &TriangleCreator::getInstance() {
    static TriangleCreator instance;
    return instance;
}

Triangle *TriangleCreator::create(const sf::Vector2f &p1, const sf::Vector2f &p2, const sf::Vector2f &p3) {
    return new Triangle(p1, p2, p3);
}

TriangleCreator::TriangleCreator() = default;