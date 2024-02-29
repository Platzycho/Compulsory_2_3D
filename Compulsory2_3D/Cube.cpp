#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Cube.h"
#include "Shader.h"

Cube::Cube(float width, float height, float depth, float r, float g, float b, float posX, float posY, float posZ) : position(glm::vec3(posX, posY, posZ)), scale(glm::vec3(1.0f, 1.0f, 1.0f))
{
    GenerateCube(width, height, depth, r, g, b);
    setupMesh();
    updateModelMatrix();
}

Cube::~Cube()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Cube::Draw(Shader& shader)
{
    shader.use();
    shader.setMat4("model", modelMatrix);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

}

void Cube::Update()
{
    
}

void Cube::SetRotation(float angle, glm::vec3 axis)
{
    rotationAngle = angle;
    rotationAxis = axis;
    updateModelMatrix();
}

void Cube::CleanUp()
{
    glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Cube::GenerateCube(float w, float h, float d, float r, float g, float b) {
    // Define the half extents of the cube
    float hw = w * 0.5f;
    float hh = h * 0.5f;
    float hd = d * 0.5f;

    glm::vec3 color = {r, g, b};

    vertices = {
        // Front face
        {{-hw, -hh,  hd}, color}, // Bottom Left
        {{ hw, -hh,  hd}, color}, // Bottom Right
        {{ hw,  hh,  hd}, color}, // Top Right
        {{-hw,  hh,  hd}, color}, // Top Left
        // Back face
        {{-hw, -hh, -hd}, color}, // Bottom Left
        {{ hw, -hh, -hd}, color}, // Bottom Right
        {{ hw,  hh, -hd}, color}, // Top Right
        {{-hw,  hh, -hd}, color}, // Top Left
        // Left face
        {{-hw, -hh, -hd}, color}, // Bottom Left
        {{-hw, -hh,  hd}, color}, // Bottom Right
        {{-hw,  hh,  hd}, color}, // Top Right
        {{-hw,  hh, -hd}, color}, // Top Left
        // Right face
        {{ hw, -hh,  hd}, color}, // Bottom Left
        {{ hw, -hh, -hd}, color}, // Bottom Right
        {{ hw,  hh, -hd}, color}, // Top Right
        {{ hw,  hh,  hd}, color}, // Top Left
        // Top face
        {{-hw,  hh,  hd}, color}, // Bottom Left
        {{ hw,  hh,  hd}, color}, // Bottom Right
        {{ hw,  hh, -hd}, color}, // Top Right
        {{-hw,  hh, -hd}, color}, // Top Left
        // Bottom face
        {{-hw, -hh, -hd}, color}, // Bottom Left
        {{ hw, -hh, -hd}, color}, // Bottom Right
        {{ hw, -hh,  hd}, color}, // Top Right
        {{-hw, -hh,  hd}, color}, // Top Left
    };

    indices = {
        // Front
        0, 1, 2, 2, 3, 0,
        // Back
        4, 5, 6, 6, 7, 4,
        // Left
        8, 9, 10, 10, 11, 8,
        // Right
        12, 13, 14, 14, 15, 12,
        // Top
        16, 17, 18, 18, 19, 16,
        // Bottom
        20, 21, 22, 22, 23, 20
    };
}

void Cube::setupMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
       
	//Position
	// Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Cube::updateModelMatrix()
{
    modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);/*
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotationAngle), rotationAxis);*/
    modelMatrix = glm::scale(modelMatrix, scale);
}
