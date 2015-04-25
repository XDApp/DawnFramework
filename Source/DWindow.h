#pragma once
#include "DawnEngineObject.h"

class DWindow :
	public DawnEngineObject
{
	DClass(DWindow);
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
	void Show();
	void Hide();
	void Minimize();
	void Restore();
	void SetSize(int Width, int Height);
	void SetPos(int X, int Y);
};

