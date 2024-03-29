#include "shapes/Rectangle.h"

class RectangleCreator {
public:
    static RectangleCreator &getInstance();

    Rectangle *create(const sf::Vector2f &p1, const sf::Vector2f &p2);

    RectangleCreator(RectangleCreator const &) = delete;

    void operator=(RectangleCreator const &) = delete;

private:
    RectangleCreator();
};