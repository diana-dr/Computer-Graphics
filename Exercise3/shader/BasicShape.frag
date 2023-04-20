#version 410 core

/* TODO Task 1 update your vertex shader so that...
 *      ...it emits the color for phong illumination
 *      ...it emits the color from the vertex shader in case you do gouraud shading there
 */

in vec3 objectColor;
in vec3 normal;
in vec3 worldPos;

/* TODO Task 1 fill these structs with values from outside the shader similar
 *      to your matric variables
 */

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

uniform bool gouraudShading;

// Ouput data
out vec3 color;

void main()
{
    // Output color = color specified in the vertex shader,
    // interpolated between all 3 surrounding vertices
    color = objectColor;

    if(!gouraudShading)
    {
        // TODO Task 1 add there code for phong lighting
        vec3 lightDir = normalize(light.position - worldPos);
        vec3 viewDir = normalize(camPos - worldPos);
        float distance = length(light.position - worldPos);

        vec3 specular = light.color * pow(max(0, dot(normal, normalize(lightDir + viewDir))), material.shininess) * material.specular;
        vec3 diffuse = light.color * max(0, dot(normal, lightDir)) * material.diffuse / (distance * distance);
        vec3 ambient = light.color * material.ambient;

        color = objectColor * (ambient + specular + diffuse);
        // END TODO
    }
}

