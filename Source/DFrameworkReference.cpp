#include "stdafx.h"
#include "DFrameworkReference.h"

DFrameworkReference::DFrameworkReference()
	:Engine(nullptr),
	WindowManager(nullptr),
	Window(nullptr),
	GraphicsManager(nullptr),
	DebugManager(nullptr)
{
}


DFrameworkReference::~DFrameworkReference()
{
}

void DFrameworkReference::Clone(DFrameworkReference *DFReference)
{
	DFrameworkObjectCopy(Engine);
	DFrameworkObjectCopy(WindowManager);
	DFrameworkObjectCopy(Window);
	DFrameworkObjectCopy(GraphicsManager);
	DFrameworkObjectCopy(WindowManager);
	DFrameworkObjectCopy(DebugManager);
}