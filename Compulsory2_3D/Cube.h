#ifndef CUBE_H
#define CUBE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Shader;


class Cube
{
public:
	Cube(int num, glm::vec3 position, glm::vec3 scale = glm::vec3(1.0f));
	~Cube();
	void Draw(Shader& shader);
	void Update();
	void SetRotation(float angle, glm::vec3 axis);
	void CleanUp();

private:
	unsigned int VAO, VBO;
	glm::vec3 position;
	glm::vec3 scale;
	glm::mat4 modelMatrix;
	glm::vec3 rotationAxis;

	float rotationAngle;

	void setupMesh(int num);
	void updateModelMatrix();
};

#endif