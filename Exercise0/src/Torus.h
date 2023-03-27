#pragma once
#ifndef TORUS_H
#define TORUS_H

#include "Shape.h"

namespace cgCourse
{
    class Torus : public Shape
    {
    public:
        Torus();
        Torus(double offset);
        void draw();
    };
}

#endif //  TORUS_H
