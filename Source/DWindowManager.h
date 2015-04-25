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
	std::vector<DWindow*> CloseWindowQueue;
public:
	DWindow* NewWindow(int Width, int Height, std::string Title);
private:
	GLFWwindow* AllocWindowObject(int Width, int Height, std::string Title);
	void DestroyWindowObject(GLFWwindow* Window);
public:
	void Initialize();
	void MakeCurrent(DWindow* Window);
	bool Update();
	void Render();
private:
	DWindow* CurrentWindow;
public:
	bool HasWindowAvailable();
	void DestroyWindow(DWindow* Window);
	
	void CloseWindow(DWindow* Window);
private:
	void ProcessCloseSignal();
};

