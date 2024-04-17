#pragma once
#include "Object.h"
#include "Plane.h"
#include "Player.h"
#include "Shader.h"
#include "Plane.h"
#include "ObjectManager.h"

class Shader;

class Scene
{
public:
	Scene();
	~Scene();

	void drawObjects(Shader& mySshader);
	void referToPlayerController(GLFWwindow* window, float deltaTime);

	void sceneSwitch(int s);


	static int scene;
private:
	Object* backWall;
	Object* leftWall;
	Object* rightWall;
	Object* frontLeftWall;
	Object* frontRightWall;
	Object* aboveDoorWall;
	Object* flatRoof;
	Object* door;
	Object* trophy;
	Object* trophy2;
	Object* trophy3;
	Object* trophy4;
	Object* trophy5;
	Object* trophy6;
	Object* trophy7;
	Object* npcCharacter;

	Player* myPlayer;

	Player* myOtherPlayer;

	Plane* myPlane;

};

