#include "stdafx.h"
#include "DGraphicsManager.h"
#include "DDebugManager.h"
#include "DAppConfig.h"
#include "DSceneManager.h"

#include "DGLVertexShader.h"
#include "DResourceLoader.h"
#include "DGLFragmentShader.h"
#include "DGLProgram.h"

DGraphicsManager::DGraphicsManager()
	:SceneManager(new DSceneManager())
{
	this->DF->SceneManager = this->SceneManager;
}


DGraphicsManager::~DGraphicsManager()
{
	DDel(SceneManager);
}


void DGraphicsManager::Update()
{
	this->SceneManager->Update();
}


void DGraphicsManager::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	this->SceneManager->Render();
}

void DGraphicsManager::PullReference(const DawnEngineObject* Object)
{
	DawnEngineObject::PullReference(Object);
	this->SceneManager->PullReference(this);
}


void DGraphicsManager::ProcessEnd()
{
	this->SceneManager->Clear();
}


bool DGraphicsManager::CanEnd()
{
	return !this->SceneManager->isEmpty();
}
