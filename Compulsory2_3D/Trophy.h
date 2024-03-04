#ifndef TROPHY_H
#define TROPHY_H
#include <vector>
#include "Cube.h"

class Cube;
class Shader;




class Trophy
{
public:
	Trophy();
	~Trophy();
	void Draw(Shader& Shader);
	void trophyPickUp(const CubeCollision& cubes);


private:
	Cube *t1;
	Cube *t2;
	Cube *t3;
	Cube *t4;
	Cube *t5;
	Cube *t6;
	Cube *t7;


};
#endif
