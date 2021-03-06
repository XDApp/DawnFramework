#pragma once
#include "DScene.h"
#include "DFramework.h"

class DScene_Main2 :
	public DScene
{
	DClass(DScene_Main2)
public:
	DScene_Main2();
	~DScene_Main2();
	void Update();
	void Render();
	void Start();
	void End();

private:
	DGLVertexShader *VShader;
	DGLFragmentShader *FShader;
	DResourceLoader *VLoader;
	DResourceLoader *FLoader;
	DGLProgram *Program;

	GLuint vertexPosition_modelspaceID;
	GLuint VertexArrayID;
	GLuint vertexbuffer;
};

