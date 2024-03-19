#include "ShapeDrawer.h"

void ShapeDrawer::drawShapes(sf::RenderWindow &window, const std::vector<std::unique_ptr<Shape>> &shapes) {
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (const auto &shape: shapes)
            shape->draw(window);
        window.display();
    }
}