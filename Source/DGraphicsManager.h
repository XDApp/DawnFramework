#pragma once
#include "DawnEngineObject.h"

class DSceneManager;

class DGraphicsManager :
	public DawnEngineObject
{
	DClass(DGraphicsManager)
public:
	DGraphicsManager();
	~DGraphicsManager();
	
	void Update();
	void Render();

	DSceneManager *SceneManager;
	void PullReference(const DawnEngineObject* Object);
	void ProcessEnd();
	bool CanEnd();
};
