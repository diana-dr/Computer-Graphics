#include "Torus.h"
#include <iostream>

// this define and include will enable M_PI from math.h.
#define _USE_MATH_DEFINES
#include <math.h>

namespace cgCourse
{
    Torus::Torus() : Torus(0.0) {}

    Torus::Torus(double offset) {
        /* TODO: Add your code here
         * First create the torus mesh
         * Then offset the vertex positions along the calculated face normals by offset
         */

    }

    void Torus::draw()
    {
        glBindVertexArray(vaoID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
        glDrawElements(GL_TRIANGLES, 3 * faces.size(), GL_UNSIGNED_INT, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }
}