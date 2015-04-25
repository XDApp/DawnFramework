#pragma once
#include "DawnEngineObject.h"
class DGraphicsManager :
	public DawnEngineObject
{
	DClass(DGraphicsManager)
public:
	DGraphicsManager();
	~DGraphicsManager();
	
	void Update();
	void Render();
};

