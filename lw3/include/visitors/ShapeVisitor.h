#ifndef SHAPEVISITOR_H
#define SHAPEVISITOR_H

#include "shapes/Shape.h"

class ShapeVisitor {
public:
    virtual void visit(Triangle *triangle) = 0;

    virtual void visit(Rectangle *rectangle) = 0;

    virtual void visit(Circle *circle) = 0;
};

#endif // SHAPEVISITOR_H