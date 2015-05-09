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
	virtual void Load();
	virtual void Destroy();
protected:
	DResourceLoader* Loader;
private:
	bool __isLoad;
public:
	bool isLoad() const;
};

