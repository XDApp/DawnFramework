#pragma once
#include "DScene.h"
#include "DFramework.h"

class DScene_Cube :
	public DScene
{
	DClass(DScene_Cube)
public:
	DScene_Cube();
	~DScene_Cube();
	void Start();
	void End();
	void Update();

private:
	DGLVertexShader *VShader;
	DGLFragmentShader *FShader;
	DResourceLoader *VLoader;
	DResourceLoader *FLoader;
	DGLProgram *Program;

	GLuint vertexPosition_modelspaceID;
	GLuint VertexArrayID;
	GLuint vertexbuffer;
public:
	void Render();
};

