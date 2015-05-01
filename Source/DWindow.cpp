#include "stdafx.h"
#include "DWindow.h"
#include "DGraphicsManager.h"
#include "DWindowManager.h"
#include "DDebugManager.h"
#include "DAppConfig.h"
#include "DSceneManager.h"

DWindow::DWindow(GLFWwindow* Window)
	:gWindow(Window)
	, GraphicsManager(new DGraphicsManager)
	, Context(nullptr)
{
	this->DF->GraphicsManager = this->GraphicsManager;
}


DWindow::~DWindow()
{
	DDel(this->GraphicsManager);
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
		if (this->GraphicsManager->CanEnd())
		{
			this->Close();
		}
		else
		{
			this->GraphicsManager->ProcessEnd();
		}
	}
}


void DWindow::Render()
{
	DF->GraphicsManager->Render();
	glfwSwapBuffers(this->gWindow);
	
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


void DWindow::PullReference(const DawnEngineObject* Object)
{
	DawnEngineObject::PullReference(Object);
	this->GraphicsManager->PullReference(this);
}


void DWindow::Initialize()
{
	DColor tmp = DF->Config->BackgroundColor();
	glClearColor(DGCR(tmp),DGCG(tmp),DGCB(tmp),DGCA(tmp));
}


GLEWContext* DWindow::GetContext()
{
	return this->Context;
}
