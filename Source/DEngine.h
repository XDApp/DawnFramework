#pragma once
#include "DawnEngineObject.h"

class DEngine :
	public DawnEngineObject
{
	DClass(DEngine)

public:
	DEngine(DAppConfig* AppConfig);
	~DEngine();
	
public:
	void Initialize();
private:
	void InitializeGLFW();
public:
	void Loop();
public:
	DWindowManager* WindowManager;
	DDebugManager* DebugManager;
	DResourceManager* ResourceManager;
};

