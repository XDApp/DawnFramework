#include "stdafx.h"
#include "DScene_Main2.h"

DScene_Main2::DScene_Main2()
{
}


DScene_Main2::~DScene_Main2()
{
}

void DScene_Main2::Update()
{
	DScene::Update();
}


void DScene_Main2::Render()
{
	DScene::Render();
	glUseProgram(Program->GetProgram());
	glEnableVertexAttribArray(vertexPosition_modelspaceID);
	glBindVertexArray(VertexArrayID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(vertexPosition_modelspaceID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0, 3); 
	glDisableVertexAttribArray(vertexPosition_modelspaceID);
}


void DScene_Main2::Start()
{
	VLoader = new DTextFileResourceLoader(DF->Config->ResourcePath() + "V2.vert.glsl");
	FLoader = new DTextFileResourceLoader(DF->Config->ResourcePath() + "F2.frag.glsl");

	VShader = new DGLVertexShader(VLoader);
	FShader = new DGLFragmentShader(FLoader);

	VLoader->Open();
	VShader->Load();
	VLoader->Close();

	FLoader->Open();
	FShader->Load();
	FLoader->Close();

	Program = new DGLProgram();

	Program->AttachShader(VShader);
	Program->AttachShader(FShader);
	Program->Load();

	delete VLoader;
	delete FLoader;

	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
	};
	static const GLfloat g_vertex_buffer_data2[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
	};
	VertexArrayID = 0;
	vertexPosition_modelspaceID = glGetAttribLocation(Program->GetProgram(), "vertexPosition_modelspace");
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}


void DScene_Main2::End()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	Program->Destroy();
	VShader->Destroy();
	FShader->Destroy();
}
