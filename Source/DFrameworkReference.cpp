#include "stdafx.h"
#include "DFrameworkReference.h"

DFrameworkReference::DFrameworkReference()
	:Engine(nullptr),
	WindowManager(nullptr),
	Window(nullptr),
	GraphicsManager(nullptr),
	DebugManager(nullptr),
	ResourceManager(nullptr),
	Config(nullptr),
	SceneManager(nullptr),
	Scene(nullptr)
{
}


DFrameworkReference::~DFrameworkReference()
{
}

void DFrameworkReference::Clone(const DFrameworkReference *DFReference)
{
	DFrameworkObjectCopy(Engine);
	DFrameworkObjectCopy(WindowManager);
	DFrameworkObjectCopy(Window);
	DFrameworkObjectCopy(GraphicsManager);
	DFrameworkObjectCopy(WindowManager);
	DFrameworkObjectCopy(DebugManager);
	DFrameworkObjectCopy(ResourceManager);
	DFrameworkObjectCopy(Config);
	DFrameworkObjectCopy(SceneManager);
	DFrameworkObjectCopy(Scene);
}

bool DFrameworkReference::CheckAvailable() const
{
	bool isAvailable = true;
	DFrameworkObjectCheck(Engine);
	DFrameworkObjectCheck(WindowManager);
	DFrameworkObjectCheck(Window);
	DFrameworkObjectCheck(GraphicsManager);
	DFrameworkObjectCheck(WindowManager);
	DFrameworkObjectCheck(DebugManager);
	DFrameworkObjectCheck(ResourceManager);
	DFrameworkObjectCheck(Config);
	DFrameworkObjectCheck(SceneManager);
	DFrameworkObjectCheck(Scene);
	return isAvailable;
}
