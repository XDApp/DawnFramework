#include "stdafx.h"
#include "DGraphicsManager.h"
#include "DDebugManager.h"
#include "DAppConfig.h"
#include "DSceneManager.h"
#include "DCanvasManager.h"

DGraphicsManager::DGraphicsManager()
	:SceneManager(new DSceneManager()),
	CanvasManager(new DCanvasManager())
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
	this->CanvasManager->PullReference(this);
}


void DGraphicsManager::ProcessEnd()
{
	this->SceneManager->Clear();
}


bool DGraphicsManager::CanEnd() const
{
	return !this->SceneManager->isEmpty();
}
