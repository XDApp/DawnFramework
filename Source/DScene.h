#pragma once
#include "DawnEngineObject.h"

class DScene :
	public DawnEngineObject
{
	DClass(DScene)
public:
	DScene();
	~DScene();
	virtual void Start();
	virtual void End();
	virtual void Update();
	virtual void Render();
};

