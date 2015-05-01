#include "stdafx.h"
#include "DGraphicsManager.h"
#include "DDebugManager.h"
#include "DAppConfig.h"
#include "DGLVertexShader.h"
#include "DResourceLoader.h"
#include "DGLFragmentShader.h"
#include "DGLProgram.h"

DGraphicsManager::DGraphicsManager()
{
}


DGraphicsManager::~DGraphicsManager()
{
}


void DGraphicsManager::Update()
{
}


void DGraphicsManager::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void DGraphicsManager::Debug_RunShader()
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

	DF->DebugManager->Message(this, "ProgramID: " + std::to_string(Program->GetProgram()));
}
