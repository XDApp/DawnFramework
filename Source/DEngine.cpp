#include "stdafx.h"
#include "DEngine.h"

DEngine::DEngine()
	: WindowManager(new DWindowManager)
{
}


DEngine::~DEngine()
{
	delete this->WindowManager;
}


void DEngine::Initialize()
{
	this->InitializeGLFW();
	this->WindowManager->Initialize();
	this->InitializeGLEW(); 
}


void DEngine::InitializeGLFW()
{
	if (!glfwInit())
	{
		//DEBUG
	}
}


void DEngine::InitializeGLEW()
{
	if (glewInit() != GLEW_OK) {
		//DEBUG
	}
}


void DEngine::Loop()
{
	this->WindowManager->Loop();
}
