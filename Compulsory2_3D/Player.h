#pragma once
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Struct.h"

class Shader;

class Player {
public:
	Player(float width, float height, float depth, float r, float g, float b, float posX, float posY, float posZ);
	~Player();

	void Draw(Shader& shader);
	void UpdatePosition(glm::vec3 direction);
	void PlayerInput(GLFWwindow* window, float deltaTime);
	void SetRotation(float angle, glm::vec3 axis);
	void GenerateCube(float w, float h, float d, float r, float g, float b);

	static bool npcPath;

	bool interact = false;
	bool buttonState = false;

private:
	unsigned int VAO, VBO, EBO;
	glm::vec3 position;
	glm::vec3 scale;
	glm::mat4 modelMatrix;
	glm::vec3 rotationAxis;
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	float speedControl = 0.5f;

	float rotationAngle;

	int trophyCollected = 0;

	void setupMesh();
	void updateModelMatrix();

};