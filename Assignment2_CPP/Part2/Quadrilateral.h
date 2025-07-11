#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H
#include <iostream>
#include "Polygon.h"

class Quadrilateral: public Polygon {
    public:
    Quadrilateral();

    //inherits setPoint() from polygon so no need to redefine

    ~Quadrilateral();
};

#endif