#include <glad/glad.h> 
#include <glm/glm.hpp>
#include "Plane.h"

Plane::Plane()
{
	vertices[0] = -0.5f; vertices[1] = -0.5f; vertices[2] = 0.0f; // Bottom left
    vertices[3] = 0.5f; vertices[4] = -0.5f; vertices[5] = 0.0f; // Bottom right
    vertices[6] = 0.5f; vertices[7] = 0.5f; vertices[8] = 0.0f; // Top right
    vertices[9] = -0.5f; vertices[10] = 0.5f; vertices[11] = 0.0f; // Top Left

    SetupPlane();
}

Plane::~Plane()
{
     glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Plane::Draw()
{
    glBindVertexArray(VAO); 
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void Plane::SetupPlane()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}
