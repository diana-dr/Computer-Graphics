#include "Torus.h"
#include <iostream>

// this define and include will enable M_PI from math.h.
#define _USE_MATH_DEFINES
#include <math.h>

namespace cgCourse
{
    Torus::Torus() : Torus(0.0){}

    Torus::Torus(double offset) {
        // TODO
        // define major radius, minor radius, and number of segments
        float majorRadius = 8.0f;
        float minorRadius = 2.0f;
        int majorSegments = 30;
        int minorSegments = 20;

        // generate vertices
        for (int i = 0; i <= majorSegments; i++) {
            float theta = i * 2.0f * static_cast<float>(M_PI) / majorSegments;
            float cosTheta = cos(theta);
            float sinTheta = sin(theta);

            for (int j = 0; j <= minorSegments; j++) {
                float phi = j * 2.0f * static_cast<float>(M_PI) / minorSegments;
                float cosPhi = cos(phi);
                float sinPhi = sin(phi);

                glm::vec3 vertex;
                vertex.x = (majorRadius + minorRadius * cosPhi) * cosTheta;
                vertex.y = (majorRadius + minorRadius * cosPhi) * sinTheta;
                vertex.z = minorRadius * sinPhi;

                // move vertex along its normal by offset factor
                vertex += glm::vec3(offset) * glm::normalize(vertex);

                
                positions.push_back(vertex);
                // calculate the distance from the center of the torus
                float distanceFromCenter = glm::length(vertex);

                // interpolate between 5 colors based on the distance
                if (distanceFromCenter < 3.0f) {
                    colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f)); // red
                }
                else if (distanceFromCenter < 5.0f) {
                    colors.push_back(glm::vec3(1.0f, 0.5f, 0.0f)); // orange
                }
                else if (distanceFromCenter < 7.0f) {
                    colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f)); // yellow
                }
                else if (distanceFromCenter < 9.0f) {
                    colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f)); // green
                }
                else {
                    colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f)); // blue
                }

                normals.push_back(glm::normalize(vertex));
            }
        }

        // generate faces
        for (int i = 0; i < majorSegments; i++) {
            for (int j = 0; j < minorSegments; j++) {
                int index0 = (minorSegments + 1) * i + j;
                int index1 = index0 + 1;
                int index2 = index0 + minorSegments + 1;
                int index3 = index2 + 1;

                faces.push_back(glm::uvec3(index0, index2, index1));
                faces.push_back(glm::uvec3(index1, index2, index3));
            }
        }

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