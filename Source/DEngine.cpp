#include "stdafx.h"

#include "DResourceManager.h"
#include "DWindowManager.h"
#include "DDebugManager.h"
#include "DEngine.h"

DEngine::DEngine()
	: WindowManager(new DWindowManager),
	DebugManager(new DDebugManager),
	ResourceManager(new DResourceManager)
{
	this->DF->Engine = this;
	this->DF->DebugManager = this->DebugManager;
	this->DF->WindowManager = this->WindowManager;
	this->DF->ResourceManager = this->ResourceManager;

	WindowManager->DF->Clone(this->DF);
	DebugManager->DF->Clone(this->DF);
	ResourceManager->DF->Clone(this->DF);
}


DEngine::~DEngine()
{
	DDel(this->WindowManager);
	DDel(this->DebugManager);
	DDel(this->ResourceManager);
}


void DEngine::Initialize()
{
	this->InitializeGLFW();
	this->WindowManager->Initialize();
	
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
	if (glewInit() != GLEW_OK) 
	{
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


void DEngine::InitializeContext()
{
	this->InitializeGLEW();
}
