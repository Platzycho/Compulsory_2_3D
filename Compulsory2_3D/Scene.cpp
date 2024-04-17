#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Scene.h"


Scene::Scene()
{
    //scene one
    backWall = new Object(0, 6.0f, 2.0f, 0.3f, 0.349f, 0.196f, 0.0f, 0.0f, 1.0f, -2.0f);
    leftWall = new Object(0, 0.3f, 2.0f, 3.7f, 0.349f, 0.196f, 0.0f, -2.85f, 1.0f, 0.0f);
    rightWall = new Object(0, 0.3f, 2.0f, 3.7f, 0.349f, 0.196f, 0.0f, 2.85f, 1.0f, 0.0f);
    frontLeftWall = new Object(0, 2.5f, 2.0f, 0.3f, 0.349f, 0.196f, 0.0f, -1.75f, 1.0f, 2.0f);
    frontRightWall = new Object(0, 2.5f, 2.0f, 0.3f, 0.349f, 0.196f, 0.0f, 1.75f, 1.0f, 2.0f);
    aboveDoorWall = new Object(0, 1.0f, 0.5f, 0.3f, 0.349f, 0.196f, 0.0f, 0.0f, 1.8f, 2.0f);
    flatRoof = new Object(0, 5.7f, 0.3f, 3.7f, 0.349f, 0.196f, 0.0f, 0.0f, 2.0f, 0.0f);
    door = new Object(0, 1.0f, 1.5f, 0.3f, 0.659f, 0.373f, 0.0f, 0.0f, 0.75f, 2.0f);

    myPlayer = new Player(0.3f, 0.3f, 0.3f, 0.7f, 0.7f, 0.7f, 4.0f, 0.15f, 4.0f);
    npcCharacter = new Object(0, 0.3f, 0.3f, 0.3f, 0.7f, 0.7f, 0.7f, 3.0f, 0.15f, 3.0f);

    trophy = new Object(0, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, -2.0f, 0.15f, 3.0f);
    trophy2 = new Object(0, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, -4.0f, 0.15f, 3.0f);
    trophy3 = new Object(0, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, -2.0f, 0.15f, 5.0f);
    trophy4 = new Object(0, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 2.0f, 0.15f, 5.0f);
    trophy5 = new Object(0, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 5.0f, 0.15f, 3.0f);
    trophy6 = new Object(0, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 6.0f, 0.15f, 3.0f);
    trophy7 = new Object(0, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, -4.0f, 0.15f, -3.0f);

    trophy->isTrophy();
    trophy2->isTrophy();
    trophy3->isTrophy();
    trophy4->isTrophy();
    trophy5->isTrophy();
    trophy6->isTrophy();
    trophy7->isTrophy();

    door->isDoor();

    myPlane = new Plane();


    //scene two

    myOtherPlayer = new Player(0.3f, 0.3f, 0.3f, 0.7f, 0.7f, 0.7f, 4.0f, 0.15f, 4.0f);
}

Scene::~Scene()
{
    if (scene == 0) {
        myOtherPlayer->~Player();

    }
    else if (scene == 1) {
        backWall->~Object();
        leftWall->~Object();
        rightWall->~Object();
        frontLeftWall->~Object();
        frontRightWall->~Object();
        aboveDoorWall->~Object();
        door->~Object();
        flatRoof->~Object();
        npcCharacter->~Object();
        myPlayer->~Player();

        trophy->~Object();
        trophy2->~Object();
        trophy3->~Object();
        trophy4->~Object();
        trophy5->~Object();
        trophy6->~Object(); 
        trophy7->~Object();
    }

    

}





void Scene::drawObjects(Shader& myShader)
{
    if (scene == 0) {
        myPlane->Draw();
        backWall->Draw(myShader);
        leftWall->Draw(myShader);
        rightWall->Draw(myShader);
        frontLeftWall->Draw(myShader);
        frontRightWall->Draw(myShader);
        aboveDoorWall->Draw(myShader);
        door->Draw(myShader);
        flatRoof->Draw(myShader);
        // npcCharacter.Draw(myShader);

        trophy->Draw(myShader);
        trophy2->Draw(myShader);
        trophy3->Draw(myShader);
        trophy4->Draw(myShader);
        trophy5->Draw(myShader);
        trophy6->Draw(myShader);
        trophy7->Draw(myShader);

        myPlayer->Draw(myShader);
    }
    else if (scene == 1) {
        myOtherPlayer->Draw(myShader);
    }
    
}



void Scene::referToPlayerController(GLFWwindow* window, float deltaTime)
{
    if (scene == 0) {
       myPlayer->PlayerInput(window, deltaTime);
    }
    else if (scene == 1) {
       myOtherPlayer->PlayerInput(window, deltaTime);
    }
}

void Scene::sceneSwitch(int s)
{
    scene = s;
}


