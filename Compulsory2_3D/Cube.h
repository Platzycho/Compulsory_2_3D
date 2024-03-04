#ifndef CUBE_H
#define CUBE_H


#include <vector>
#include "bullet/btBulletDynamicsCommon.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct Vertex {
	glm::vec3 Position, Color;
};

class Shader;

class Cube
{
public:
	Cube(float width, float height, float depth, 
         float r, float g, float b, 
         float posX, float posY, float posZ);
	~Cube();
	void Draw(Shader& shader);
	void UpdatePosition(glm::vec3 direction);
	void PlayerInput(GLFWwindow* window);
	void SetRotation(float angle, glm::vec3 axis);
	void CleanUp();
	void GenerateCube(float w, float h, float d, float r, float g, float b);
	void initializePhysics(btDiscreteDynamicsWorld* dynamicsWorld);
	void updateFromPhysics();

	btCollisionShape* collisionShape;
	btDefaultMotionState* motionState;
	btRigidBody* rigidBody;
	

private:
	

	unsigned int VAO, VBO, EBO;
	glm::vec3 position;
	glm::vec3 newPosition;
	glm::vec3 scale;
	glm::mat4 modelMatrix;
	glm::vec3 rotationAxis;
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	float rotationAngle;

	void setupMesh();
	void updateModelMatrix();
};

#endif