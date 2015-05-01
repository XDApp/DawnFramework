#pragma once
#include "DawnEngineObject.h"

class DEngine;
class DWindowManager;
class DDebugManager;
class DWindow;
class DGraphicsManager;
class DResourceManager;

#define DFrameworkObjectCopy(ClassName)\
	this->ClassName = (this->ClassName == nullptr) ? (DFReference->ClassName) : (this->ClassName)

class DFrameworkReference
{
	DClass(DFrameworkReference)
public:
	DFrameworkReference();
	~DFrameworkReference();
	
	DEngine* Engine;
	DWindowManager* WindowManager;
	DDebugManager* DebugManager;
	DWindow* Window;
	DGraphicsManager* GraphicsManager;
	DResourceManager* ResourceManager;

	void Clone(DFrameworkReference* DFReference);
};

