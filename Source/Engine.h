#pragma once

class Engine
{
public:
	Engine();
	~Engine();
protected:
	GLFWwindow* window;
public:
	int InitializeOpenGL();
};

