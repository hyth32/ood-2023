#include "RectangleCreator.h"

RectangleCreator &RectangleCreator::getInstance() {
    static RectangleCreator instance;
    return instance;
}

Rectangle *RectangleCreator::create(const sf::Vector2f &p1, const sf::Vector2f &p2) {
    return new Rectangle(p1, p2);
}

RectangleCreator::RectangleCreator() {}