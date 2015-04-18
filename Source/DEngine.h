#pragma once

#include "DWindowManager.h"

class DEngine :
	public DawnEngineObject
{
public:
	DEngine();
	~DEngine();
public:
	void Initialize();
private:
	void InitializeGLFW();
	void InitializeGLEW();
public:
	void Loop();
public:
	DWindowManager* WindowManager;
};

