#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "House.h"
#include "Shader.h"
#include "Cube.h"

 

House::House(): backWall(6.0f, 2.0f, 0.5f, 1.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f),
    leftWall(5.0f, 2.0f, 0.5f, 1.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f),
    rightWall(5.0f, 2.0f, 0.5f, 1.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f),
    frontLeftWall(2.0f, 2.0f, 0.5f, 1.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f),
    frontRightWall(2.0f, 2.0f, 0.5f, 1.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f),
    aboveDoorWall(2.0f, 1.0f, 0.5f, 1.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f),
    frontRoof(2.0f, 5.0f, 2.0f, 1.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f),
    backRoof(2.0f, 5.0f, 2.0f, 1.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f),
    leftRoof(2.0f, 5.0f, 2.0f, 1.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f),
    rightRoof(2.0f, 5.0f, 2.0f, 1.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f),
    door(2.0f, 1.0f, 0.5f, 1.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f)
{
   /* generateHouse(w, h, d, r, g, b);*//*
    generateBasicHouse(r, g, b);
    setupMesh();
    updateModelMatrix();*/

   

}

House::~House()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void House::Draw(Shader& shader)
{
    /*shader.use();
    shader.setMat4("model", modelMatrix);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);*/
    glm::mat4 model = glm::mat4(1.0f); 

    model = glm::translate(model, backWall.position); // Assuming each Cube has a position
    shader.setMat4("model", model);
    backWall.Draw(shader);
    backWall.Draw(shader);
    frontLeftWall.Draw(shader);   
    frontRightWall.Draw(shader);
    aboveDoorWall.Draw(shader);
    door.Draw(shader);
    frontRoof.Draw(shader);
    backRoof.Draw(shader);
    leftRoof.Draw(shader);
    rightRoof.Draw(shader);
    leftWall.Draw(shader);
    rightWall.Draw(shader);

}

void House::generateHouse(float w, float h, float d, float r, float g, float b)
{
    //float hw = w * 0.5f; // Half width
    //float hh = h * 0.5f; // Half height
    //float hd = d * 0.5f; // Half depth
    //float roofHeight = h * 0.5f; // Arbitrary roof height

    //glm::vec3 color = {r, g, b};

    //vertices = {

    //    {{-hw, -hh, -hd}, color},  // Bottom-Back-Left
    //    {{ hw, -hh, -hd}, color},  // Bottom-Back-Right
    //    {{ hw, -hh,  hd}, color},  // Bottom-Front-Right
    //    {{-hw, -hh,  hd}, color},  // Bottom-Front-Left
    //    {{-hw,  hh, -hd}, color},  // Top-Back-Left
    //    {{ hw,  hh, -hd}, color},  // Top-Back-Right
    //    {{ hw,  hh,  hd}, color},  // Top-Front-Right
    //    {{-hw,  hh,  hd}, color},  // Top-Front-Left
    //    {{-hw,  hh, -hd}, color},  //Back-Left
    //    {{ hw,  hh, -hd}, color},  //Back-Right
    //    {{0,  hh + roofHeight, 0}, color}, // Top-Mid
    //};

    //indices = {
    //    3, 7, 6, 6, 2, 3, 
    //    // Back wall
    //    1, 5, 4, 4, 0, 1,
    //    // Left wall
    //    0, 4, 7, 7, 3, 0,
    //    // Right wall
    //    5, 1, 2, 2, 6, 5,
    //    // Roof
    //    4, 5, 10, 5, 9, 10, 9, 6, 10, 6, 7, 10, 
    //};
}

void House::generateBasicHouse(float r, float g, float b)
{
   
}

void House::setupMesh()
{
 //   glGenVertexArrays(1, &VAO);
 //   glGenBuffers(1, &VBO);
 //   glGenBuffers(1, &EBO);
 //   
 //   glBindVertexArray(VAO);
 //   glBindBuffer(GL_ARRAY_BUFFER, VBO);
 //   glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexHouse), vertices.data(), GL_STATIC_DRAW);

 //   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
 //   glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
 //      
	////Position
 //   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexHouse), (void*)offsetof(VertexHouse, Position));
 //   glEnableVertexAttribArray(0);

 //   // Color
 //   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexHouse), (void*)offsetof(VertexHouse, Color));
 //   glEnableVertexAttribArray(1);

 //   glBindBuffer(GL_ARRAY_BUFFER, 0);
 //   glBindVertexArray(0);
}

void House::updateModelMatrix()
{
	//modelMatrix = glm::mat4(1.0f);
 //   modelMatrix = glm::translate(modelMatrix, position);/*
 //   modelMatrix = glm::rotate(modelMatrix, glm::radians(rotationAngle), rotationAxis);*/
 //   modelMatrix = glm::scale(modelMatrix, scale);
}
