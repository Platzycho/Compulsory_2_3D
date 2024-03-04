#include "Trophy.h"
#include <cmath>
#include <iostream>

	

Trophy::Trophy() : t1(nullptr), t2(nullptr), t3(nullptr), t4(nullptr), t5(nullptr), t6(nullptr), t7(nullptr)
{
	float moveX = 3;
	t1 = new Cube(0.1f, 0.1f, 0.1f, 0.2f, 0.2f, 0.2f, -3 + moveX, 0, -0.67 * pow(-3, 2) + 5.83 *-3 -7.00); 
	std::cout << Cube::cubes.size() << std::endl;
	t2 = new Cube(0.1f, 0.1f, 0.1f, 0.2f, 0.2f, 0.2f, -2 + moveX, 0, -0.67 * pow(-2, 2) + 5.83 *-2 -7.00); 
	std::cout << Cube::cubes.size() << std::endl;
	t3 = new Cube(0.1f, 0.1f, 0.1f, 0.2f, 0.2f, 0.2f, -1 + moveX, 0, -0.67 * pow(-1, 2) + 5.83 *-1 -7.00); 	
	std::cout << Cube::cubes.size() << std::endl;
	t4 = new Cube(0.1f, 0.1f, 0.1f, 0.2f, 0.2f, 0.2f, -0 + moveX, 0, -0.67 * pow(-0, 2) + 5.83 *-0 -7.00); 
	std::cout << Cube::cubes.size() << std::endl;
	t5 = new Cube(0.1f, 0.1f, 0.1f, 0.2f, 0.2f, 0.2f, 1 + moveX, 0, -0.67 * pow( 1, 2) + 5.83 * 1 -7.00); 
	std::cout << Cube::cubes.size() << std::endl;
	t6 = new Cube(0.1f, 0.1f, 0.1f, 0.2f, 0.2f, 0.2f, 2 + moveX, 0, -0.67 * pow( 2, 2) + 5.83 * 2 -7.00); 
	std::cout << Cube::cubes.size() << std::endl;
	t7 = new Cube(0.1f, 0.1f, 0.1f, 0.2f, 0.2f, 0.2f, 3 + moveX, 0, -0.67 * pow( 3, 2) + 5.83 * 3 -7.00); 
	std::cout << Cube::cubes.size() << std::endl;

}

Trophy::~Trophy()
{
	delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete t5;
    delete t6;
    delete t7;
}

void Trophy::Draw(Shader& Shader)
{
	if (t1) t1->Draw(Shader);
	if (t2) t2->Draw(Shader);
	if (t3) t3->Draw(Shader);
	if (t4) t4->Draw(Shader);
	if (t5) t5->Draw(Shader);
	if (t6) t6->Draw(Shader);
	if (t7) t7->Draw(Shader);	
}

void Trophy::trophyPickUp(const CubeCollision& cubes)
{
	
}

