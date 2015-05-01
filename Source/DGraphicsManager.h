#pragma once
#include "DawnEngineObject.h"

class DGLVertexShader;
class DGLFragmentShader;
class DResourceLoader;
class DGLProgram;
class DGLShader;

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
	DGLProgram *Program;

	void Debug_RunShader();
};
