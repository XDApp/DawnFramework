#include "stdafx.h"
#include "DWindow.h"
#include "DWindowManager.h"

DWindow::DWindow(GLFWwindow* Window)
	:gWindow(Window)
{
}


DWindow::~DWindow()
{
}


GLFWwindow* DWindow::GetWindow()
{
	return this->gWindow;
}


void DWindow::Update()
{
	if (glfwWindowShouldClose(gWindow))
	{
		this->Close();
	}
}


void DWindow::Initialize()
{
	DF->WindowManager->MakeCurrent(this);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}


void DWindow::Render()
{
}


void DWindow::Close()
{
	DF->WindowManager->CloseWindow(this);
}
