#include "Player.h"
#include "Shader.h"
#include "Object.h"
#include "ObjectManager.h"


Player::Player(float width, float height, float depth, float r, float g, float b, float posX, float posY, float posZ) : position(glm::vec3(posX, posY, posZ)), scale(glm::vec3(1.0f, 1.0f, 1.0f))
{
	GenerateCube(width, height, depth, r, g, b);
	setupMesh();
	rotationAngle = 0;
	rotationAxis = glm::vec3(1.0f, 1.0f, 1.0f);
	updateModelMatrix();
}

Player::~Player()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Player::Draw(Shader& shader)
{
	shader.use();
	shader.setMat4("model", modelMatrix);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Player::UpdatePosition(glm::vec3 direction)
{
	glm::vec3 tentativePosition = position + direction * speedControl;
	AABB playerBox = CalculateAABB({ tentativePosition, scale });

	bool collisionDetected = false;
	for (const auto& object : ObjectManager::getInstance().getObjects()) {
		if (CheckAABBCollision(playerBox, CalculateAABB(object->getCollisionData()))) {
			collisionDetected = true;

			if (interact == true) {
				object->BEGONE_THOT(1000.f, 1000.f, 1000.f);
				break;
			}
			if (object->trophy == true) {
				object->BEGONE_THOT(1000.f, 1000.f, 1000.f);
				trophyCollected += 1;
				std::cout << "Collected: " << trophyCollected << " trophies!" << std::endl;
				break;	
			}
			else {
				break;
			}
			
		}

	}

	//std::cout << collisionDetected << std::endl;

	if (!collisionDetected) {
		position = tentativePosition;
		updateModelMatrix();
	}
}

void Player::PlayerInput(GLFWwindow* window, float deltaTime)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		UpdatePosition(glm::vec3(0.0f, 0.0f, -10.f) * deltaTime);
		updateModelMatrix();
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		UpdatePosition(glm::vec3(0.0f, 0.0f, 10.f) * deltaTime);
		updateModelMatrix();
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		UpdatePosition(glm::vec3(-10.f, 0.0f, 0.0f) * deltaTime);
		updateModelMatrix();
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		UpdatePosition(glm::vec3(10.f, 0.0f, 0.0f) * deltaTime);
		updateModelMatrix();
	}

	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
		interact = true;
	}

	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_RELEASE) {
		interact = false;
	}

	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
		if (npcPath == true) {
			npcPath = false;
		}
	}

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {

		if (npcPath == false) {
			npcPath = true;
		}
		
	}
}

void Player::SetRotation(float angle, glm::vec3 axis)
{
	rotationAngle = angle;
	rotationAxis = axis;
	updateModelMatrix();
}

void Player::GenerateCube(float w, float h, float d, float r, float g, float b)
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

void Player::setupMesh()
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

void Player::updateModelMatrix()
{
	modelMatrix = glm::mat4(1.0f);
	modelMatrix = glm::translate(modelMatrix, position);
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotationAngle), rotationAxis);
	modelMatrix = glm::scale(modelMatrix, scale);
}
