#include <fstream>
#include <vector>
#include <memory>
#include "Shape.h"

class ShapeReader {
public:
    static std::vector<std::unique_ptr<Shape>> readShapesFromFile(const std::string &filename);
};