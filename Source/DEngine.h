#pragma once
#include "DawnEngineObject.h"

class DEngine :
	public DawnEngineObject
{
	DClass(DEngine)

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
	DDebugManager* DebugManager;
	DResourceManager* ResourceManager;
	void InitializeContext();
};

