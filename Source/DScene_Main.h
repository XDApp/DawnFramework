#pragma once
#include "DScene.h"
#include "DFramework.h"

class DScene_Main :
	public DScene
{
public:
	DScene_Main();
	~DScene_Main();
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

	GLuint VertexArrayID;
	GLuint vertexbuffer;
};

