#pragma once
#include "DawnEngineObject.h"

class DGLVertexShader;
class DGLFragmentShader;
class DResourceLoader;

class DGraphicsManager :
	public DawnEngineObject
{
	DClass(DGraphicsManager)
public:
	DGraphicsManager();
	~DGraphicsManager();
	
	void Update();
	void Render();

	DGLVertexShader *VShader;
	DGLFragmentShader *FShader;
	DResourceLoader *VLoader;
	DResourceLoader *FLoader;
	void Debug_RunShader();
};
