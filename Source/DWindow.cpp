#include "stdafx.h"
#include "DWindow.h"
#include "DGraphicsManager.h"
#include "DWindowManager.h"

DWindow::DWindow(GLFWwindow* Window)
	:gWindow(Window)
	, GraphicsManager(new DGraphicsManager)
{
	this->DF->GraphicsManager = this->GraphicsManager;
	this->GraphicsManager->DF->Clone(this->DF);
}


DWindow::~DWindow()
{
	delete this->GraphicsManager;
}


GLFWwindow* DWindow::GetWindow()
{
	return this->gWindow;
}


void DWindow::Update()
{
	DF->GraphicsManager->Update();
	if (glfwWindowShouldClose(this->GetWindow()))
	{
		this->Close();
	}
}


void DWindow::Initialize()
{
	DF->WindowManager->MakeCurrent(this);
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
}


void DWindow::Render()
{
	DF->GraphicsManager->Render();
}


void DWindow::Close()
{
	DF->WindowManager->CloseWindow(this);
}


void DWindow::Show()
{
	glfwShowWindow(this->GetWindow());
}


void DWindow::Hide()
{
	glfwHideWindow(this->GetWindow());
}


void DWindow::Minimize()
{
	glfwIconifyWindow(this->GetWindow());
}


void DWindow::Restore()
{
	glfwRestoreWindow(this->GetWindow());
}


void DWindow::SetSize(int Width, int Height)
{
	glfwSetWindowSize(this->GetWindow(), Width, Height);
}


void DWindow::SetPos(int X, int Y)
{
	glfwSetWindowPos(this->GetWindow(), X, Y);
}
