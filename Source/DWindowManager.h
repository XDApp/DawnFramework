#pragma once
#include "DawnEngineObject.h"

class DWindowManager :
	public DawnEngineObject
{
public:
	DWindowManager();
	~DWindowManager();
private:
	std::vector<DWindow*> Windows;
public:
	DWindow* NewWindow(int Width, int Height, std::string Title);
private:
	GLFWwindow* AllocWindowObject(int Width, int Height, std::string Title);
	void DestroyWindowObject(GLFWwindow* Window);
public:
	void Initialize();
	void MakeCurrent(DWindow* Window);
	void Loop();
private:
	DWindow* CurrentWindow;
private:
	void PreLoop();
	void PostLoop();
	void Update();
public:
	bool HasWindowAvailable();
	void DestroyWindow(DWindow* Window);
	
};

