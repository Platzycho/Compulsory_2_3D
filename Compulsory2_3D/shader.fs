#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec3 Normal;

uniform vec3 lightDir;

void main() {

    vec3 norm = normalize(Normal);
    vec3 lightDirection = normalize(-lightDir);

    float diff = max(dot(norm, lightDirection), 0.0);
    vec3 diffuse = diff * ourColor;

    FragColor = vec4(diffuse, 1.0);
}