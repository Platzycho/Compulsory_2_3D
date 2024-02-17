#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec3 aColor;

out vec3 ourColor; // Pass color to the fragment shader
out vec3 Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    //vec3 worldNormal = mat3(transpose(inverse(view * model))) * aNormal;
    Normal = mat3(transpose(inverse(projection))) * aNormal; // Transform normals to world space
    ourColor = aColor; // Set the output color to the input color from the VBO
    
}