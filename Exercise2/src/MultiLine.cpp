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
		float length = 0.35;

		for (int i = 0; i < _vertices.size(); i++) {
			positions.push_back(_vertices[i]);
			positions.push_back(_vertices[i] + length * _normals[i]);

			colors.push_back({ 1.0f, 1.0f, 0 });
			colors.push_back({ 1.0f, 1.0f, 0 });
		}

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

