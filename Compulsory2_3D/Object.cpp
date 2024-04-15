#include "Object.h"
#include "ObjectManager.h"
#include "Player.h"
#include <iostream>
int trophyAmount = 0;


Object::Object(int objectID, float width, float height, float depth, float r, float g, float b, float posX, float posY, float posZ) : position(glm::vec3(posX, posY, posZ)), scale(glm::vec3(1.0f, 1.0f, 1.0f))
{

	if (objectID == 0) {
		GenerateCube(width, height, depth, r, g, b);
	}
	else {
		std::cout << "Invalid ID" << std::endl;
	}

	setupMesh();
	rotationAngle = 0;
	rotationAxis = glm::vec3(1.0f, 1.0f, 1.0f);
	updateModelMatrix();
    ObjectManager::getInstance().addObject(this);
}

Object::~Object()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Object::Draw(Shader& shader)
{
	shader.use();
	shader.setMat4("model", modelMatrix);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Object::UpdateNpcPosition(float deltaTime)
{
    //y = 0.33x ^ 3 - 1.50x ^ 2 + 3.17x
    parameter += (moving ? 1 : -1) * deltaTime * speed;

    //y = -0.67x^2 + 5.83x -7.00

    if (Player::npcPath == false) {
        position = glm::vec3(0.33f * pow(parameter, 3) - 1.5f * pow(parameter, 2) + 3.17 * parameter, 1.f, parameter + 3.f);
        updateModelMatrix();
    }
    else if (Player::npcPath == true) {
        position = glm::vec3(-0.67f * pow(parameter, 2) + 5.83f * parameter - 7.f, 1.f, parameter + 3.f);
        updateModelMatrix();
    }

    //std::cout << position.z << std::endl;

    if (parameter >= 3.2f) {
        parameter = 3.2f;
        moving = false;
    }
    else if (parameter <= 0.0f) {
        parameter = 0.0f;
        moving = true;
    }


}

void Object::SetRotation(float angle, glm::vec3 axis)
{
    rotationAngle = angle;
    rotationAxis = axis;
    updateModelMatrix();
}

Collision Object::getCollisionData() const
{
    return Collision{ position, scale };
}

void Object::GenerateCube(float w, float h, float d, float r, float g, float b)
{
    float hw = w * 0.5f;
    float hh = h * 0.5f;
    float hd = d * 0.5f;

    glm::vec3 color = { r, g, b };

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

void Object::isTrophy()
{  
    trophy = true;
}

void Object::isDoor()
{
    door = true;
}

void Object::BEGONE_THOT(float x, float y, float z)
{
    position = glm::vec3(x, y, z);    
    updateModelMatrix();
}

void Object::rotateDoor()
{
    if (doorOpened == false) {
        rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
        rotationAngle = 90;
        position = position + glm::vec3(0.6f, 0.0f, 0.3f);
        updateModelMatrix();
    }
    else if (doorOpened == true) {
        rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
        rotationAngle = 0;
        position = position + glm::vec3(-0.6f, 0.0f, -0.3f);
        updateModelMatrix();
    }
    
}

void Object::setupMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Object::updateModelMatrix()
{
    modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotationAngle), rotationAxis);
    modelMatrix = glm::scale(modelMatrix, scale);
}
