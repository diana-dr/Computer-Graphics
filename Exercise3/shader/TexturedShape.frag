#version 410 core

/* TODO Task 2 update your vertex shader so that...
 *      ...it has texture samplers declared
 *      ...it outputs a diffuse texture as diffuse color
 *      ...it uses a light map to modify the specular highlights
 */

in vec3 objectColor;

/* TODO Task 2 Add the required input data */

in vec2 texCoord;
in vec3 worldPos;
in mat3 tbnMatrix;

// END TODO

/* TODO Task 2 declare texture samplers here */

uniform sampler2D texMap;
uniform sampler2D normalMap;
uniform sampler2D specMap;

// END TODO

/* TODO Task 2 fill these structs with values from outside the shader similar
 *      to your matric variables
 */

uniform struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
} material;

uniform struct Light{
    vec3 position;
    vec3 color;
} light;

uniform vec3 camPos;

// TODO END

out vec4 color;

void main()
{

    /* TODO Task 2 add the source code to do phong shading but with the values of the color, normal and specular texture.
     *      Remember that you can also use the color output for debugging of the
     *      texture maps and texture coordinates in case that you face troubles.
     */

    vec3 normal = texture(normalMap, texCoord).rgb;
    normal = normalize(normal * 2.0 - 1.0);
    normal = tbnMatrix * normal;

    vec3 texColor = texture(texMap, texCoord).rgb;
    vec3 specColor = texture(specMap, texCoord).rgb;

    vec3 lightVec = normalize(light.position - worldPos);
    vec3 viewVec = normalize(camPos - worldPos);

    float distance = length(light.position - worldPos);
    vec3 specular = vec3(1.0f, 1.0f, 1.0f) 
                    * pow(max(0, dot(normal, (lightVec + viewVec) / 2)), material.shininess) 
                    * specColor;
    vec3 diffuse = light.color * max(0, dot(normal, lightVec)) / (distance * distance) * texColor;
    vec3 ambient = light.color * material.ambient * texColor;
    color = vec4((specular + diffuse + ambient), 1.0f);

    // TODO END
}

