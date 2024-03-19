#include "visitors/ShapeVisitor.h"
#include <ostream>

class AreaPerimeterPrinter : public ShapeVisitor {
public:
    AreaPerimeterPrinter(std::ostream &out);
    void visit(Triangle *triangle) override;
    void visit(Rectangle *rectangle) override;
    void visit(Circle *circle) override;

private:
    std::ostream &out;
};