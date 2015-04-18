#pragma once
#include "DawnEngineObject.h"
class DWindowManager :
	public DawnEngineObject
{
public:
	DWindowManager();
	~DWindowManager();
private:
	std::vector<GLFWwindow*> Windows;
public:
	GLFWwindow* NewWindow(int Width, int Height, std::string Title);
private:
	GLFWwindow* AllocWindowObject(int Width, int Height, std::string Title);
	void DestroyWindowObject(GLFWwindow* Window);
public:
	void Initialize();
	void MakeCurrent(GLFWwindow* Window);
	void Loop();
private:
	GLFWwindow* CurrentWindow;
private:
	void PreLoop();
	void PostLoop();
	void Update();
public:
	bool HasWindowAvailable();
};

