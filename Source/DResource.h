#pragma once
#include "DawnEngineObject.h"

class DResourceLoader;

class DResource :
	public DawnEngineObject
{
	DClass(DResource)
public:
	DResource(DResourceLoader* loader);
	~DResource();
	virtual void Load() = 0;
	virtual void Destroy() = 0;
protected:
	DResourceLoader* Loader;
};

