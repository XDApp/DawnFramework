#pragma once
#include "DawnEngineObject.h"

class DEngine;
class DWindowManager;
class DDebugManager;
class DWindow;

class DFrameworkReference
{
	DClass(DFrameworkReference);
public:
	DFrameworkReference();
	~DFrameworkReference();
	DEngine* Engine;
	DWindowManager* WindowManager;
	DDebugManager* DebugManager;
	DWindow* Window;
};

