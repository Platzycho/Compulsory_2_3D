#pragma once
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Struct.h"
#include "Shader.h"

class Shader;

class NPCPath;

class Object
{
public:
	Object(int objectID, float width, float height, float depth, float r, float g, float b, float posX, float posY, float posZ);
	~Object();

	void Draw(Shader& shader);
	void UpdateNpcPosition(float deltaTime);
	void SetRotation(float angle, glm::vec3 axis);
	void GenerateCube(float w, float h, float d, float r, float g, float b);
	void isTrophy();
	void isDoor();
	void BEGONE_THOT(float x, float y, float z);
	void rotateDoor();
	Collision getCollisionData() const;

	// const NPCPath& path, float deltaTime
	bool trophy = false;
	bool door = false;
	bool doorOpened = false;

	

private:
	unsigned int VAO, VBO, EBO;
	glm::vec3 position;
	glm::vec3 scale;
	glm::mat4 modelMatrix;
	glm::vec3 rotationAxis;
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	float parameter = 0.0f;
	bool moving = true;
	float speed = 1.f;

	float rotationAngle;

	bool npcPath = false;

	int meshKey = 0;

	void setupMesh();
	void updateModelMatrix();

};

