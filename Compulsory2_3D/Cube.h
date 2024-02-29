#ifndef CUBE_H
#define CUBE_H


#include <vector>

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
	void Update();
	void SetRotation(float angle, glm::vec3 axis);
	void CleanUp();
	void GenerateCube(float w, float h, float d, float r, float g, float b);

	


private:
	unsigned int VAO, VBO, EBO;
	glm::vec3 position;
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