#pragma once
#include "DawnEngineObject.h"

class DScene;

class DSceneManager :
	public DawnEngineObject
{
	DClass(DSceneManager)
private:
	std::vector<DScene*> SceneQueue;
	DScene *CurrentScene;
public:
	DSceneManager();
	~DSceneManager();
	void PullReference(const DawnEngineObject* Object);
	void Update();
	void Render();

	template <class SceneClass> void PushScene()
	{
		this->SceneQueue.push_back(dynamic_cast<DScene*>(new SceneClass));
	}

	template <class SceneClass> void GotoScene()
	{
		this->Clear();
		this->SceneQueue.push_back(dynamic_cast<DScene*>(new SceneClass));
	}

	void PopScene();
	void Clear();

	bool isEmpty() const;
	DScene* GetCurrentScene() const;
	void PushSceneObject(DScene* Scene);
	void GotoSceneObject(DScene *Scene);

private:
	DScene *lstScene;
	void ProcessStart(DScene *Scene);
	void ProcessEnd(DScene *Scene);
};

