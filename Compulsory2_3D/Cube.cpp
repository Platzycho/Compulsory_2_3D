#include "Cube.h"
#include "Shader.h"

float vertices[] = {
	// Back face		//Normal            // Color
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,// Bottom-left
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,// Bottom-right
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,// Top-right
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,// Top-right (again, for the second triangle)
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,// Top-left
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,// Bottom-left (again, to close the face)

    // Front face		 //Normal            // Color
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-left
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-right
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right (again)
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-left
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-left (again)

    // Left face		 //Normal           // Color
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right (front)
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-left (back)
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-left (back)
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-left (back, again)
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-right (front)
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right (front, again)

    // Right face		 //Normal            // Color
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-left (front)
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right (back)
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-right (back)
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-right (back, again)
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-left (front)
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-left (front, again)

    // Bottom face		//Normal            // Color
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right (back)
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-left (back)
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-left (front)
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-left (front, again)
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-right (front)
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right (back, again)

    // Top face		    //Normal            // Color
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-left (back)
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right (back)
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-right (front)
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-right (front, again)
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom-left (front)
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f // Top-left (back, again)

};

float verticesTwo[] = {
	// Back face		//Normal            // Color
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-right
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-right
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-right (again, for the second triangle)
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-left
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left (again, to close the face)

    // Front face		//Normal            // Color
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-right
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-right
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-right (again)
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-left
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left (again)

    // Left face		 //Normal           // Color
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-right (front)
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-left (back)
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left (back)
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left (back, again)
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-right (front)
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-right (front, again)

    // Right face		 //Normal           // Color
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-left (front)
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-right (back)
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-right (back)
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-right (back, again)
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left (front)
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-left (front, again)

    // Bottom face		 //Normal           // Color
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-right (back)
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-left (back)
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left (front)
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left (front, again)
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-right (front)
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-right (back, again)

    // Top face		     //Normal          // Color
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-left (back)
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-right (back)
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-right (front)
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-right (front, again)
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left (front)
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f  // Top-left (back, again)

};

float verticesThree[] = {
    // Back face		 //Normal		    // Color
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-left
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-right
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, // Top-right
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-right (again, for the second triangle)
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-left
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-left (again, to close the face)

    // Front face		 //Normal		    // Color
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-left
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-right
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-right
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-right (again)
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-left
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-left (again)

    // Left face		 //Normal		    // Color
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-right (front)
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-left (back)
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-left (back)
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-left (back, again)
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-right (front)
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-right (front, again)

    // Right face		 //Normal		    // Color
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-left (front)
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-right (back)
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-right (back)
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-right (back, again)
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-left (front)
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-left (front, again)

    // Bottom face		 //Normal		    // Color
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-right (back)
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-left (back)
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-left (front)
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-left (front, again)
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-right (front)
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-right (back, again)

    // Top face			 //Normal	        // Color
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-left (back)
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-right (back)
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-right (front)
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-right (front, again)
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-left (front)
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Top-left (back, again)
};

Cube::Cube(int num, glm::vec3 position, glm::vec3 scale) : position(position), scale(scale)
{
    setupMesh(num);
    updateModelMatrix();
}

Cube::~Cube()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Cube::Draw(Shader& shader)
{
    shader.use();
    shader.setMat4("model", modelMatrix);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);

}

void Cube::Update()
{

}

void Cube::SetRotation(float angle, glm::vec3 axis)
{
    rotationAngle = angle;
    rotationAxis = axis;
    updateModelMatrix();
}

void Cube::CleanUp()
{
    glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Cube::setupMesh(int num)
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    switch(num){
        case 1:
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
            break;
        case 2:
            glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTwo), verticesTwo, GL_STATIC_DRAW);
            break;
        case 3:        
            glBufferData(GL_ARRAY_BUFFER, sizeof(verticesThree), verticesThree, GL_STATIC_DRAW);
            break;
        default:
            return;
    }

	//Position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

    //Normal
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Cube::updateModelMatrix()
{
    modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotationAngle), rotationAxis);
    modelMatrix = glm::scale(modelMatrix, scale);
}
