#pragma once
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Struct.h"

class Object;

class ObjectManager {
public:
	static ObjectManager& getInstance() {
		static ObjectManager instance;
		return instance;
	}

	void addObject(Object* obj) {
		objects.push_back(obj);

	}

	std::vector<Object*>& getObjects() {
		return objects;

	}

	std::vector<Object*>& getObject(int object) {
		return objects;
	}

private:
	std::vector<Object*> objects;

	ObjectManager() {}
	ObjectManager(ObjectManager const&) = delete;
	void operator =(ObjectManager const&) = delete;


};

