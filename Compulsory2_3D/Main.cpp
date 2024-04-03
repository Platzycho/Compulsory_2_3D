#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Shader.h"
#include "Camera.h"
#include "Cube.h"
#include "Trophy.h"
#include "Plane.h"
#include <iostream>
#include <algorithm>
#include <cmath>

struct CallbackData {
    Shader* myShader;
    Camera* myCamera;
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow* window);

void mouse_callback(GLFWwindow* window, double xpos, double ypos);

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

Camera camera(glm::vec3(-0.0589525f, 11.9224f, 12.7897f));

glm::vec3 camPosition = glm::vec3(-0.0589525f, 11.9224f, 12.7897f);

glm::vec3 cameraDirection = glm::vec3(0.0f, -1.0f, -1.0f);

glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

float deltaTime = 0.0f;
float lastFrame = 0.0f;
float rotationAngle = 0.0f;

int main() {
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to init GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
   
    Shader myShader("shader.vs", "shader.fs");

    //House


    Cube backWall(6.0f, 2.0f, 0.3f, 0.349f, 0.196f, 0.0f, 0.0f, 1.0f, -2.0f); 

    Cube leftWall(0.3f, 2.0f, 3.7f, 0.349f, 0.196f, 0.0f, -2.85f, 1.0f, 0.0f);

    Cube rightWall(0.3f, 2.0f, 3.7f, 0.349f, 0.196f, 0.0f, 2.85f, 1.0f, 0.0f); 

    Cube frontLeftWall(2.5f, 2.0f, 0.3f, 0.349f, 0.196f, 0.0f, -1.75f, 1.0f, 2.0f); 

    Cube frontRightWall(2.5f, 2.0f, 0.3f, 0.349f, 0.196f, 0.0f, 1.75f, 1.0f, 2.0f); 

    Cube aboveDoorWall(1.0f, 0.5f, 0.3f, 0.349f, 0.196f, 0.0f, 0.0f, 1.8f, 2.0f); 

    Cube flatRoof(5.7f, 0.3f, 3.7f, 0.349f, 0.196f, 0.0f, 0.0f, 2.0f, 0.0f); 

    Cube door(1.0f, 1.5f, 0.3f, 0.659f, 0.373f, 0.0f, 0.0f, 0.75f, 2.0f); 

    Cube myPlayer(0.3f, 0.3f, 0.3f, 0.7f, 0.7f, 0.7f, 4.0f, 0.15f, 4.0f);

    Trophy trophies; 

    std::cout << Cube::cubes.size() << std::endl;
     
    Plane myPlane; 

    cameraDirection = glm::normalize(cameraDirection);

	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)800 / (float)600, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(camPosition, camPosition + cameraDirection, up);

    CallbackData callbackData;
    callbackData.myShader = &myShader;
    callbackData.myCamera = &camera;

    glfwSetScrollCallback(window, scroll_callback);

    glfwSetWindowUserPointer(window, &callbackData);

    glfwSetCursorPosCallback(window, mouse_callback);

    glEnable(GL_DEPTH_TEST);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	while(!glfwWindowShouldClose(window))
	{
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		processInput(window);
        myPlayer.PlayerInput(window);

		glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);/*
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);*/

		myShader.use();

      
        // Camera/View transformation
        
	    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)800 / (float)600, 0.1f, 100.0f);
        //glm::mat4 view = camera.GetViewMatrix();

        glm::mat4 model = glm::mat4(1.0f); 
        glUniformMatrix4fv(glGetUniformLocation(myShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));

        myShader.setMat4("projection", projection);
        myShader.setMat4("view", view);

        myPlane.Draw();
        backWall.Draw(myShader);
        leftWall.Draw(myShader);
        rightWall.Draw(myShader);
        frontLeftWall.Draw(myShader);
        frontRightWall.Draw(myShader);
        aboveDoorWall.Draw(myShader);
        door.Draw(myShader);
        flatRoof.Draw(myShader);

        myPlayer.Draw(myShader);

        trophies.Draw(myShader);

      /*  std::cout << camera.Position.x  << ", " << camera.Position.y << ", " << camera.Position.z <<  std::endl;*/
          for(size_t i = 0; i < Cube::cubes.size(); ++i) {
          for(size_t j = i + 1; j < Cube::cubes.size(); ++j) {
            if(Cube::collisionDetection(Cube::cubes[i], Cube::cubes[j])) {

            // Handle collision
               
        }
    }
}

        glfwSwapBuffers(window);
        glfwPollEvents();
       
		
	}

  /*cube.CleanUp();
    cube2.CleanUp();*/
    backWall.CleanUp();
    leftWall.CleanUp();
    rightWall.CleanUp();
    frontLeftWall.CleanUp();
    frontRightWall.CleanUp();
    aboveDoorWall.CleanUp();
    door.CleanUp();
    flatRoof.CleanUp(); 
    myPlayer.~Cube(); 

  
     

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
    
    CallbackData* data = static_cast<CallbackData*>(glfwGetWindowUserPointer(window));

     if (data != nullptr && data->myShader != nullptr) {
        glm::mat4 projection = glm::perspective(glm::radians(data->myCamera->Zoom), (float)width / (float)height, 0.1f, 100.0f);
        data->myShader->use(); 
        glUniformMatrix4fv(glGetUniformLocation(data->myShader->ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    }
}

void processInput(GLFWwindow* window)
{	
    //Camera movement
	

	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    static float lastX = 800.0f / 2.0;
    static float lastY = 600.0f / 2.0;
    static bool firstMouse = true;

    CallbackData* data = static_cast<CallbackData*>(glfwGetWindowUserPointer(window));
    if(firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    if (data && data->myCamera) {
        data->myCamera->ProcessMouseMovement(xoffset, yoffset);
    }
    

}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    CallbackData* data = static_cast<CallbackData*>(glfwGetWindowUserPointer(window));
    if(data && data->myCamera) {
        data->myCamera->ProcessMouseScroll(yoffset);
    }
}
