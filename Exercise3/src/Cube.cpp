#include "Cube.h"
#include <iostream>
#include <glm/gtx/string_cast.hpp>
namespace cgCourse
{
	Cube::Cube() : Shape()
	{
		// set geometry with respect to local origin
		positions = {
			{ -1.0f, -1.0f, -1.0f },	// index 0
			{ -1.0f, -1.0f, 1.0f },
			{ -1.0f, 1.0f, 1.0f },
			{ -1.0f, 1.0f, -1.0f },

			{ 1.0f, 1.0f, 1.0f },		// index 4
			{ 1.0f, -1.0f, 1.0f },
			{ 1.0f, -1.0f, -1.0f },
			{ 1.0f, 1.0f, -1.0f },

			{ -1.0f, -1.0f, -1.0f },	// index 8
			{ 1.0f, -1.0f, -1.0f },
			{ 1.0f, -1.0f, 1.0f },
			{ -1.0f, -1.0f, 1.0f },

			{ 1.0f, 1.0f, 1.0f },		// index 12
			{ 1.0f, 1.0f, -1.0f },
			{ -1.0f, 1.0f, -1.0f },
			{ -1.0f, 1.0f, 1.0f },

			{ -1.0f, -1.0f, -1.0f },	// index 16
			{ -1.0f, 1.0f, -1.0f },
			{ 1.0f, 1.0f, -1.0f },
			{ 1.0f, -1.0f, -1.0f },

			{ 1.0f, 1.0f, 1.0f },		// index 20
			{ -1.0f, 1.0f, 1.0f },
			{ -1.0f, -1.0f, 1.0f },
			{ 1.0f, -1.0f, 1.0f }
		};

		colors = {
			{ 0.8f, 0.0f, 0.0f },
			{ 0.8f, 0.0f, 0.0f },
			{ 0.8f, 0.0f, 0.0f },
			{ 0.8f, 0.0f, 0.0f },

            { 0.8f, 0.8f, 0.0f },
            { 0.8f, 0.8f, 0.0f },
            { 0.8f, 0.8f, 0.0f },
            { 0.8f, 0.8f, 0.0f },

			{ 0.0f, 0.8f, 0.0f },
			{ 0.0f, 0.8f, 0.0f },
			{ 0.0f, 0.8f, 0.0f },
			{ 0.0f, 0.8f, 0.0f },

			{ 0.0f, 0.0f, 0.8f },
			{ 0.0f, 0.0f, 0.8f },
			{ 0.0f, 0.0f, 0.8f },
			{ 0.0f, 0.0f, 0.8f },

			{ 0.0f, 0.8f, 0.8f },
			{ 0.0f, 0.8f, 0.8f },
			{ 0.0f, 0.8f, 0.8f },
			{ 0.0f, 0.8f, 0.8f },

			{ 0.8f, 0.0f, 0.8f },
			{ 0.8f, 0.0f, 0.8f },
			{ 0.8f, 0.0f, 0.8f },
			{ 0.8f, 0.0f, 0.8f }
		};

		normals = {
			{ -1.0f, 0.0f, 0.0f },
			{ -1.0f, 0.0f, 0.0f },
			{ -1.0f, 0.0f, 0.0f },
			{ -1.0f, 0.0f, 0.0f },

			{ 1.0f, 0.0f, 0.0f },
			{ 1.0f, 0.0f, 0.0f },
			{ 1.0f, 0.0f, 0.0f },
			{ 1.0f, 0.0f, 0.0f },

			{ 0.0f, -1.0f, 0.0f },
			{ 0.0f, -1.0f, 0.0f },
			{ 0.0f, -1.0f, 0.0f },
			{ 0.0f, -1.0f, 0.0f },

			{ 0.0f, 1.0f, 0.0f },
			{ 0.0f, 1.0f, 0.0f },
			{ 0.0f, 1.0f, 0.0f },
			{ 0.0f, 1.0f, 0.0f },

			{ 0.0f, 0.0f, -1.0f },
			{ 0.0f, 0.0f, -1.0f },
			{ 0.0f, 0.0f, -1.0f },
			{ 0.0f, 0.0f, -1.0f },

			{ 0.0f, 0.0f, 1.0f },
			{ 0.0f, 0.0f, 1.0f },
			{ 0.0f, 0.0f, 1.0f },
			{ 0.0f, 0.0f, 1.0f }
		};

        /* TODO Task 2 set the texture coordinates for the cube similar
		 *       to the positions array. After you set the texture coordinates
		 *       for this object try to access them in the shader and
		 *       check by color output if they are ok. You can also
		 *       compare your results in the end with the final image
		 *       so that the texture orientation is done right.
		 *
		*/

        // texCoords->push_back(...

//        for(int i = 0; i < positions.size(); i++) {
//            texCoords.push_back(glm::vec2(0.0,0.0));
//        }

        for (int i = 0; i < positions.size(); i += 4)
        {
            texCoords.push_back(glm::vec2(0.0, 0.0));
            texCoords.push_back(glm::vec2(0.0, 1.0));
            texCoords.push_back(glm::vec2(1.0, 1.0));
            texCoords.push_back(glm::vec2(1.0, 0.0));
        }

        //TODO END

		faces = {
			{ 0, 1, 2 }, { 2, 3, 0 },
			{ 4, 5, 6 }, { 6, 7, 4 },
			{ 8, 9, 10 }, { 10, 11, 8 },
			{ 12, 13, 14 }, { 14, 15, 12 },
			{ 16, 17, 18 }, { 18, 19, 16 },
			{ 20, 21, 22 }, { 22, 23, 20 }
		};

        /* TODO Task 2 add the tangent vectors for the cube here to
         *       to the tangent arrays
         */
//        for(int i = 0; i < positions.size(); i++) {
//            tangents.push_back(glm::vec3(0.0,0.0,0.0));
//        }
        // tangents...
        tangents.resize(positions.size());

        for(int i = 0; i < faces.size(); i++) {
            int i1 = faces[i].x;
            int i2 = faces[i].y;
            int i3 = faces[i].z;

            glm::vec3 v1 = positions[i1];
            glm::vec3 v2 = positions[i2];
            glm::vec3 v3 = positions[i3];

            glm::vec2 uv1 = texCoords[i1];
            glm::vec2 uv2 = texCoords[i2];
            glm::vec2 uv3 = texCoords[i3];

            glm::vec3 deltaPos1 = v2 - v1;
            glm::vec3 deltaPos2 = v3 - v1;

            glm::vec2 deltaUV1 = uv2 - uv1;
            glm::vec2 deltaUV2 = uv3 - uv1;

            float r = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV1.y * deltaUV2.x);
            glm::vec3 tangent = (deltaPos1 * deltaUV2.y - deltaPos2 * deltaUV1.y)*r;

            tangents[i1] += tangent;
            tangents[i2] += tangent;
            tangents[i3] += tangent;
        }

        for(int i = 0; i < tangents.size(); i++) {
            tangents[i] = glm::normalize(tangents[i]);
        }

        // TODO END
	}
}

