#include "stdafx.h"

#include "DResourceManager.h"
#include "DWindowManager.h"
#include "DDebugManager.h"
#include "DEngine.h"

DEngine::DEngine(DAppConfig* AppConfig)
	: WindowManager(new DWindowManager),
	DebugManager(new DDebugManager),
	ResourceManager(new DResourceManager)
{
	this->DF->Engine = this;
	this->DF->DebugManager = this->DebugManager;
	this->DF->WindowManager = this->WindowManager;
	this->DF->ResourceManager = this->ResourceManager;
	this->DF->Config = AppConfig;

	this->DebugManager->PullReference(this);
	this->WindowManager->PullReference(this);
	this->ResourceManager->PullReference(this);
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

void DEngine::Loop()
{
	do
	{
		DF->WindowManager->Update();
		DF->WindowManager->Render();
	} while (DF->WindowManager->HasWindowAvailable());
	glfwTerminate();
}
