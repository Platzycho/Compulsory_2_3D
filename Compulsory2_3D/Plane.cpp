#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Plane.h"

float verticesPlane[] = {
//  x     y/up  z/inwards
    -10.5f, 0.0f, -10.5f, 0.0f, 0.1f, 0.0f,//Bottom left
    10.5f, 0.0f, -10.5f, 0.0f, 0.1f, 0.0f,// Bottom right
    10.5f, 0.0f, 10.5f, 0.0f, 0.1f, 0.0f,// Top right
    -10.5f, 0.0f, 10.5f, 0.0f, 0.1f, 0.0f // Top Left
    };

Plane::Plane()
{
	

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
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPlane), verticesPlane, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}
