#include "stdafx.h"
#include "DSceneManager.h"
#include "DScene.h"

DSceneManager::DSceneManager()
	: PopFlag(0)
	, ClearFlag(false)
{
}


DSceneManager::~DSceneManager()
{
	this->_Clear();
}


void DSceneManager::PullReference(const DawnEngineObject* Object)
{
	DawnEngineObject::PullReference(Object);
	DScene *CurrentScene = this->GetCurrentScene();
	if (CurrentScene)CurrentScene->PullReference(this);
}


void DSceneManager::Update()
{
	this->ProcessPopScene();
	this->ProcessPushScene();
	DScene* CurrentScene = this->GetCurrentScene();
	if (CurrentScene)
	{
		CurrentScene->Update();
	}
}


void DSceneManager::Render()
{
	DScene* CurrentScene = this->GetCurrentScene();
	if (CurrentScene)
	{
		CurrentScene->Render();
	}
}


void DSceneManager::PopScene()
{
	if (!PushQueue.empty())
	{
		PushQueue.pop();
	}
	else
	{
		this->PopFlag++;
	}
}


void DSceneManager::Clear()
{
	this->ClearFlag = true;
}


void DSceneManager::ProcessPopScene()
{
	while (this->PopFlag > 0)
	{
		this->_PopScene();
		this->PopFlag--;
	}
}


void DSceneManager::_PopScene()
{
	if (!this->Scenes.empty())
	{
		this->Scenes.pop_back();
	}
}


void DSceneManager::_NewScene(DScene* Scene)
{
	this->Scenes.push_back(Scene);
}


void DSceneManager::ProcessStart(DScene* Scene)
{
	Scene->PullReference(this);
	Scene->Start();
}


void DSceneManager::ProcessEnd(DScene* Scene)
{
	Scene->End();
}


DScene* DSceneManager::GetCurrentScene() const
{
	if (Scenes.empty())return nullptr;
	else return this->Scenes.back();
}


void DSceneManager::ProcessPushScene()
{
	DScene* CurrentScene = this->GetCurrentScene();
	if (this->ClearFlag || !this->PushQueue.empty())
	{
		if (CurrentScene)ProcessEnd(CurrentScene);

		if (this->ClearFlag)
		{
			this->_Clear();
		}
		else if (!this->PushQueue.empty())
		{
			DDel(this->GetCurrentScene());
			_PopScene();
		}
		while (!PushQueue.empty())
		{
			this->Scenes.push_back(PushQueue.back());
			PushQueue.pop();
		}
		CurrentScene = this->GetCurrentScene();
		if (CurrentScene)ProcessStart(CurrentScene);
	}
}


void DSceneManager::_Clear()
{
	while (!Scenes.empty())
	{
		delete Scenes.back();
		Scenes.pop_back();
	}
}


bool DSceneManager::isEmpty() const
{
	return this->Scenes.empty() && this->PushQueue.empty();
}


void DSceneManager::PushSceneObject(DScene* Scene)
{
	this->PushQueue.push(Scene);
}
