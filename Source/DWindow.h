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
	void Update();
	void Initialize();
	void Render();
	void Close();
};

