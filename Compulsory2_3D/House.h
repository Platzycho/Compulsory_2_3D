#ifndef HOUSE_H
#define HOUSE_H

struct VertexHouse{
	glm::vec3 Position, Color;
};

class Shader;


class House
{
public:
	House();
	~House();

	void Draw(Shader& shader);
	void generateHouse(float w, float h, float d, float r, float g, float b);
	void generateBasicHouse(float r, float g, float b);
private:
	unsigned int VAO, VBO, EBO;
	glm::vec3 position;
	glm::vec3 scale;
	glm::mat4 modelMatrix;
	std::vector<VertexHouse> vertices;
	std::vector<unsigned int> indices;

	void setupMesh();
	void updateModelMatrix();
	Cube backWall;
	Cube leftWall;
	Cube rightWall;
	Cube frontLeftWall;
	Cube frontRightWall;
	Cube aboveDoorWall;
	Cube frontRoof;
	Cube backRoof;
	Cube leftRoof;
	Cube rightRoof;
	Cube door;
};

#endif