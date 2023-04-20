#version 410 core

/* TODO Task 1 update your vertex shader so that...
 *      ...it emits all necessary information to the fragment shader for phong illumination
 *      ...it emits the color in case you do gouraud shading
 */

// Input vertex data
layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vColor;
layout(location = 2) in vec3 vNormal;

// Output data will be interpolated for each fragment.
// Tip: Try to use the flat modifier to make color associations of a fragment visible for debugging.
out vec3 objectColor;
out vec3 normal;
out vec3 worldPos;

// matrices that stay constant for the whole mesh.
uniform mat4 modelMatrix;
uniform mat4 mvpMatrix;

uniform bool gouraudShading;

// TODO Task 1 Additional variables
uniform vec3 camPos;

uniform struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
} material;

uniform struct Light {
    vec3 position;
    vec3 color;
} light;

// END TODO

void main()
{
    normal = mat3(transpose(inverse(modelMatrix))) * vNormal;

    // Output position of the vertex, in clip space : MVP * vPosition
    gl_Position = mvpMatrix * vec4(vPosition, 1);

    // The color of each vertex will be interpolated
    // to produce the color of each fragment
    // ... uncomment this for color
    objectColor = vColor;

    // ... uncomment this for color according to normals
    // objectColor = vNormal;

    worldPos = vec3(modelMatrix * vec4(vPosition, 1));

    if(gouraudShading)
    {
        // TODO Task 1 add there code for gouraud shading
        vec3 lightDir = normalize(light.position - worldPos);
        vec3 viewDir = normalize(camPos - worldPos);
        float distance = length(light.position - worldPos);

        vec3 specular = light.color * pow(max(0, dot(normal, normalize(lightDir + viewDir))), material.shininess) * material.specular;
        vec3 diffuse = light.color * max(0, dot(normal, lightDir)) * material.diffuse / (distance * distance);
        vec3 ambient = light.color * material.ambient;

        objectColor = vColor * (ambient + specular + diffuse);
        // END TODO
    }
}

