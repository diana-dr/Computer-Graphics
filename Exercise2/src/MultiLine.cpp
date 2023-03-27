#include "MultiLine.h"

#include <iostream>
#include <cmath>

namespace cgCourse
{
	MultiLine::MultiLine(const std::vector<glm::vec3> & _vertices,
						 const std::vector<glm::vec3> & _normals
						 ) : Shape()
	{
		// TODO: initialize positions, colors, and normals
		// Set the positions of the vertices
		positions = _vertices;

		// Set the colors to white
		colors.resize(_vertices.size(), glm::vec3(1.0f, 1.0f, 1.0f));

		// Set the normals to the given values
		normals = _normals;

		// Create the vertex array object and vertex buffer objects
		createVertexArray(0, 0, 1);
	}

	void MultiLine::draw() const
	{
		// TODO: complete code to draw the normals as lines
        // Bind the vertex array object
        glBindVertexArray(vaoID);

        // Draw the lines
        glDrawArrays(GL_LINES, 0, positions.size());

        // Unbind the vertex array object
        glBindVertexArray(0);
	}
}

