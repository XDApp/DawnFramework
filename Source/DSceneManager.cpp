#include "stdafx.h"
#include "DSceneManager.h"
#include "DScene.h"

DSceneManager::DSceneManager()
	:CurrentScene(nullptr),
	lstScene(nullptr)
{
}


DSceneManager::~DSceneManager()
{
	this->Clear();
}


void DSceneManager::PullReference(const DawnEngineObject* Object)
{
	DawnEngineObject::PullReference(Object);
	if (CurrentScene)CurrentScene->PullReference(this);
}

void DSceneManager::Update()
{
	CurrentScene = this->GetCurrentScene();
	if (CurrentScene != lstScene)
	{
		ProcessEnd(lstScene);
		ProcessStart(CurrentScene);
		lstScene = CurrentScene;
	}
	if (CurrentScene)CurrentScene->Update();
}

void DSceneManager::Render()
{
	if (CurrentScene)CurrentScene->Render();
}

template <class SceneClass> void PushScene()
{
	this->SceneQueue.push(dynamic_cast<DScene*>(new SceneClass));
}

template <class SceneClass> void GotoScene()
{
	this->Clear();
	this->SceneQueue.push(dynamic_cast<DScene*>(new SceneClass));
}

void DSceneManager::PopScene()
{
	DScene* Target = this->SceneQueue.back();
	this->SceneQueue.pop_back();
	DDel(Target);
}
void DSceneManager::Clear()
{
	while (!this->isEmpty())this->PopScene();
}

bool DSceneManager::isEmpty() const
{
	return this->SceneQueue.empty();
}

DScene* DSceneManager::GetCurrentScene() const
{
	return this->SceneQueue.empty() ? nullptr : this->SceneQueue.back();
}

void DSceneManager::PushSceneObject(DScene* Scene)
{
	this->SceneQueue.push_back(Scene);
}

void DSceneManager::GotoSceneObject(DScene *Scene)
{
	this->Clear();
	this->SceneQueue.push_back(Scene);
}

void DSceneManager::ProcessStart(DScene *Scene)
{
	if (Scene)
	{
		Scene->PullReference(this);
		Scene->Start();
	}
}

void DSceneManager::ProcessEnd(DScene *Scene)
{
	if(Scene)Scene->End();
}