#pragma once
#include "DawnEngineObject.h"

class DWindow :
	public DawnEngineObject
{
	DClass(DWindow)
private:
	GLFWwindow* gWindow;
public:
	DWindow(GLFWwindow* Window);
	~DWindow();
	

	GLFWwindow* GetWindow() const;
	void Update();
	void Render();
	void Close();
	void Show();
	void Hide();
	void Minimize();
	void Restore();
	void SetSize(int Width, int Height);
	void SetPos(int X, int Y);
	DGraphicsManager* GraphicsManager;
	virtual void PullReference(const DawnEngineObject* Object);
	void Initialize();
public:
	GLEWContext* Context;

	GLEWContext* GetContext() const;
};

