#include "stdafx.h"

#include "DWindowManager.h"
#include "DDebugManager.h"
#include "DEngine.h"

DEngine::DEngine()
	: WindowManager(new DWindowManager),
	DebugManager(new DDebugManager)
{
	this->DF->Engine = this;
	this->DF->DebugManager = this->DebugManager;
	this->DF->WindowManager = this->WindowManager;

	WindowManager->DF->Engine = this->DF->Engine;
	WindowManager->DF->DebugManager = this->DF->DebugManager;
	WindowManager->DF->WindowManager = this->DF->WindowManager;

	DebugManager->DF->Engine = this->DF->Engine;
	DebugManager->DF->DebugManager = this->DF->DebugManager;
	DebugManager->DF->WindowManager = this->DF->WindowManager;

}


DEngine::~DEngine()
{
	delete this->WindowManager;
	delete this->DebugManager;
}


void DEngine::Initialize()
{
	this->InitializeGLFW();
	this->WindowManager->Initialize();

	this->InitializeGLEW(); 

	DF->DebugManager->Message(this, "Engine is Initialized Successfully");
}


void DEngine::InitializeGLFW()
{
	if (!glfwInit())
	{
		DF->DebugManager->Error(this, "GLFW Failed to Initialize.");
	}
	else
	{
		DF->DebugManager->Message(this, "GLFW is Initialized Successfully.");
	}
}


void DEngine::InitializeGLEW()
{
	if (glewInit() != GLEW_OK) {
		DF->DebugManager->Error(this, "GLEW Failed to Initialize.");
	}
	else
	{
		DF->DebugManager->Message(this, "GLEW is Initialized Successfully.");
	}
}


void DEngine::Loop()
{
	do
	{
		DF->WindowManager->Update();
		DF->WindowManager->Render();
	} while (DF->WindowManager->HasWindowAvailable());
	glfwTerminate();
}
