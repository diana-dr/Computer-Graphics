#version 410 core

layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vColor;
layout(location = 2) in vec3 vNormal;

out vec3 objectColor;

uniform mat4 modelMatrix;
uniform mat4 mvpMatrix;

void main()
{
	gl_Position = mvpMatrix * vec4(vPosition, 1);

	// TODO: use the normal matrix
	// Calculate the normal matrix from the model matrix
	mat3 normalMatrix = transpose(inverse(mat3(modelMatrix)));
	
	// Transform the normal vector using the normal matrix
	vec3 transformedNormal = normalize(normalMatrix * vNormal);

	objectColor = vColor;

	// TODO: uncomment this line to display the normals as color
	objectColor = vNormal;
}

