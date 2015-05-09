#pragma once
#include "DawnEngineObject.h"

class DSceneManager;
class DCanvasManager;

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
	DCanvasManager *CanvasManager;
	virtual void PullReference(const DawnEngineObject* Object);
	void ProcessEnd();
	bool CanEnd() const;
};
