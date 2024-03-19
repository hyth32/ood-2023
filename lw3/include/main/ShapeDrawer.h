#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "shapes/Shape.h"

class ShapeDrawer {
public:
    static void drawShapes(sf::RenderWindow &window, const std::vector<std::unique_ptr<Shape>> &shapes);
};