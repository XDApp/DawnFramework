#include "stdafx.h"

#include "Engine.h"

Engine::Engine()
	: window(NULL)
{

}


Engine::~Engine()
{
}


int Engine::InitializeOpenGL()
{
	if (!glfwInit())
	{
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1280, 720, "Dawn Game Framework", NULL, NULL);
	if (window == NULL){
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		return -1;
	}
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	do{
		glfwSwapBuffers(window);
		glfwPollEvents();
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);
	glfwTerminate();
	return 0;
}
