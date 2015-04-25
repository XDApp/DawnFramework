#pragma once
#include "DawnEngineObject.h"

class DWindow :
	public DawnEngineObject
{
private:
	GLFWwindow* gWindow;
public:
	DWindow(GLFWwindow* Window);
	~DWindow();
	GLFWwindow* GetWindow();
};

