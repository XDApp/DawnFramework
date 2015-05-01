#include "stdafx.h"
#include "DGraphicsManager.h"
#include "DDebugManager.h"
#include "DAppConfig.h"
#include "DGLVertexShader.h"
#include "DResourceLoader.h"
#include "DGLFragmentShader.h"

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
	glClear(GL_COLOR_BUFFER_BIT);
}


void DGraphicsManager::Debug_RunShader()
{
	VLoader = new DTextFileResourceLoader(DF->Config->ResourcePath() + "V.vertexshader");
	FLoader = new DTextFileResourceLoader(DF->Config->ResourcePath() + "F.fragmentshader");
	
	VShader = new DGLVertexShader(VLoader);
	FShader = new DGLFragmentShader(FLoader);

	VLoader->Open();
	VShader->Load();
	VLoader->Close();

	FLoader->Open();
	FShader->Load();
	FLoader->Close();

	DF->DebugManager->Message(this, "FShaderID: " + std::to_string(FShader->GetShader()));
}
