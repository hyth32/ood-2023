#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <iostream>

class Shape {
public:
    virtual void draw(sf::RenderWindow &window) = 0;

    virtual double perimeter() const = 0;

    virtual double area() const = 0;

    virtual void setColor(const sf::Color &color) = 0;
};

class ColorDecorator : public Shape {
public:
    ColorDecorator(Shape *shape, sf::Color color)
            : shape(shape), color(color) {}

    void draw(sf::RenderWindow &window) override {
        shape->setColor(color);
        shape->draw(window);
    }

    double perimeter() const override {
        return shape->perimeter();
    }

    double area() const override {
        return shape->area();
    }

    void setColor(const sf::Color &color) override {
        this->color = color;
    }

private:
    Shape *shape;
    sf::Color color;
};

class Triangle : public Shape {
public:
    Triangle(const sf::Vector2f &p1, const sf::Vector2f &p2, const sf::Vector2f &p3)
            : triangle(3) {
        triangle.setPoint(0, p1);
        triangle.setPoint(1, p2);
        triangle.setPoint(2, p3);
    }

    void draw(sf::RenderWindow &window) override {
        window.draw(triangle);
    }

    void setColor(const sf::Color &color) override {
        triangle.setFillColor(color);
    }

    double perimeter() const override {
        return dist(triangle.getPoint(0), triangle.getPoint(1)) +
               dist(triangle.getPoint(1), triangle.getPoint(2)) +
               dist(triangle.getPoint(2), triangle.getPoint(0));
    }

    double area() const override {
        double p = perimeter() / 2;
        return sqrt(p * (p - dist(triangle.getPoint(0), triangle.getPoint(1))) *
                    (p - dist(triangle.getPoint(1), triangle.getPoint(2))) *
                    (p - dist(triangle.getPoint(2), triangle.getPoint(0))));
    }

private:
    sf::ConvexShape triangle;

    static double dist(const sf::Vector2f &a, const sf::Vector2f &b) {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }
};

class Rectangle : public Shape {
public:
    Rectangle(const sf::Vector2f &p1, const sf::Vector2f &p2)
            : rectangle(sf::Vector2f(abs(p1.x - p2.x), abs(p1.y - p2.y))) {
        rectangle.setPosition(std::min(p1.x, p2.x), std::min(p1.y, p2.y));
    }

    void draw(sf::RenderWindow &window) override {
        window.draw(rectangle);
    }

    void setColor(const sf::Color &color) override {
        rectangle.setFillColor(color);
    }

    double perimeter() const override {
        return 2 * (rectangle.getSize().x + rectangle.getSize().y);
    }

    double area() const override {
        return rectangle.getSize().x * rectangle.getSize().y;
    }

private:
    sf::RectangleShape rectangle;
};

class Circle : public Shape {
public:
    Circle(const sf::Vector2f &center, float radius)
            : circle(radius) {
        circle.setPosition(center);
    }

    void draw(sf::RenderWindow &window) override {
        window.draw(circle);
    }

    void setColor(const sf::Color &color) override {
        circle.setFillColor(color);
    }

    double perimeter() const override {
        return 2 * M_PI * circle.getRadius();
    }

    double area() const override {
        return M_PI * pow(circle.getRadius(), 2);
    }

private:
    sf::CircleShape circle;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "Error: Could not open file " << argv[1] << "\n";
        return 1;
    }

    std::ofstream output("output.txt");

    std::vector<Shape *> shapes;
    std::string line;
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;
        if (type == "TRIANGLE:") {
            sf::Vector2f p1, p2, p3;
            char ch;
            iss >> ch >> ch >> ch >> p1.x >> ch >> p1.y >> ch >> ch >> ch >> ch >> p2.x >> ch >> p2.y >> ch >> ch >> ch >> ch >> p3.x >> ch >> p3.y;
            Shape *triangle = new Triangle(p1, p2, p3);
            Shape *coloredTriangle = new ColorDecorator(triangle, sf::Color::Red);
            shapes.push_back(coloredTriangle);
        } else if (type == "RECTANGLE:") {
            sf::Vector2f p1, p2;
            char ch;
            iss >> ch >> ch >> ch >> p1.x >> ch >> p1.y >> ch >> ch >> ch >> ch >> p2.x >> ch >> p2.y;
            Shape *rectangle = new Rectangle(p1, p2);
            Shape *coloredRectangle = new ColorDecorator(rectangle, sf::Color::Green);
            shapes.push_back(coloredRectangle);
        } else if (type == "CIRCLE:") {
            sf::Vector2f center;
            float radius;
            char ch;
            iss >> ch >> ch >> center.x >> ch >> center.y >> ch >> ch >> ch >> radius;
            Shape *circle = new Circle(center, radius);
            Shape *coloredCircle = new ColorDecorator(circle, sf::Color::Blue);
            shapes.push_back(coloredCircle);
        }
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes");
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (Shape *shape: shapes)
            shape->draw(window);
        window.display();
    }

    for (Shape *shape: shapes) {
        output << "P=" << shape->perimeter() << "; S=" << shape->area() << std::endl;
        delete shape;
    }

    return 0;
}
