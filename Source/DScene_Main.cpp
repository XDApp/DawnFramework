#include "stdafx.h"
#include "DScene_Main.h"

DScene_Main::DScene_Main()
{
}


DScene_Main::~DScene_Main()
{
}


void DScene_Main::Update()
{
	DScene::Update();
}


void DScene_Main::Render()
{
	DScene::Render(); 
	glUseProgram(Program->GetProgram());
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
	glEnableVertexAttribArray(vertexPosition_modelspaceID);
	glBindVertexArray(VertexArrayID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(vertexPosition_modelspaceID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(vertexPosition_modelspaceID);
}


void DScene_Main::Start()
{
	VLoader = new DTextFileResourceLoader(DF->Config->ResourcePath() + "V.vert.glsl");
	FLoader = new DTextFileResourceLoader(DF->Config->ResourcePath() + "F.frag.glsl");

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


	MatrixID = glGetUniformLocation(Program->GetProgram(), "MVP");
	vertexPosition_modelspaceID = glGetAttribLocation(Program->GetProgram(), "vertexPosition_modelspace");
	glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	glm::mat4 View = glm::lookAt(
		glm::vec3(4, 3, 3),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
		);
	glm::mat4 Model = glm::mat4(1.0f);
	MVP = Projection * View * Model;

	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
	};

	static const GLushort g_element_buffer_data[] = { 0, 1, 2 };

	VertexArrayID = 0;
	vertexPosition_modelspaceID = glGetAttribLocation(Program->GetProgram(), "vertexPosition_modelspace");
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}


void DScene_Main::End()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);

	Program->Destroy();
	VShader->Destroy();
	FShader->Destroy();
}
