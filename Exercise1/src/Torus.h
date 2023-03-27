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
        glm::vec3 interpolateColors(float width, float threshold, glm::vec3 color1, glm::vec3 color2);
        void draw();
    };
}

#endif //  TORUS_H