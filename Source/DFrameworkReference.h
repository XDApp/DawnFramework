#pragma once
#include "DawnEngineObject.h"

class DEngine;
class DWindowManager;
class DDebugManager;
class DWindow;
class DGraphicsManager;
class DResourceManager;
class DAppConfig;
class DSceneManager;
class DScene;

#define DFrameworkObjectCopy(ClassName)\
	this->ClassName = (DFReference->ClassName != nullptr) ? (DFReference->ClassName) : (this->ClassName)
#define DFrameworkObjectCheck(ClassName)\
	isAvailable = (isAvailable&&((this->ClassName)!=nullptr))

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
	DSceneManager* SceneManager;
	DScene* Scene;
	DAppConfig* Config;

	void Clone(const DFrameworkReference* DFReference);
	bool CheckAvailable() const;
};

