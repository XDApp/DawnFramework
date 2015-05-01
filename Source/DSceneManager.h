#pragma once
#include "DawnEngineObject.h"

class DScene;

class DSceneManager :
	public DawnEngineObject
{
	DClass(DSceneManager)
private:
	std::vector<DScene*> Scenes;
	std::queue<DScene*> PushQueue;
public:
	DSceneManager();
	~DSceneManager();
	void PullReference(const DawnEngineObject* Object);
	void Update();
	void Render();
	template <class SceneClass> void PushScene()
	{
		this->PushQueue.push(dynamic_cast<DScene*>(new SceneClass));
	}

	template <class SceneClass> void GotoScene()
	{
		this->PushQueue.clear();
		this->ClearFlag = true;
		this->PushQueue.push(dynamic_cast<DScene*>(new SceneClass));
	}

	void PopScene();
	void Clear();
private:
	void ProcessPopScene();
	int PopFlag;
	void _PopScene();
	void _NewScene(DScene* Scene);
	void ProcessStart(DScene* Scene);
	void ProcessEnd(DScene* Scene);
public:
	DScene* GetCurrentScene();
	void ProcessPushScene();
private:
	bool ClearFlag;
public:
	void _Clear();
	bool isEmpty();
	void PushSceneObject(DScene* Scene);
};

