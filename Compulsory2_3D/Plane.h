#ifndef PLANE_H
#define PLANE_H




class Plane
{
public:
	Plane();
	~Plane();

	void Draw();
	void SetupPlane();

private:
	unsigned int VAO, VBO;
	float vertices[12];
};

#endif