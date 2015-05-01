#include "stdafx.h"
#include "DGLProgram.h"
#include "DGLShader.h"
#include "DApp.h"
#include "DDebugManager.h"

DGLProgram::DGLProgram()
	:DResource(nullptr)
{
}


DGLProgram::~DGLProgram()
{
}


void DGLProgram::AttachShader(DGLShader* Shader)
{
	Shaders.push_back(Shader);
}


void DGLProgram::DetachShader(DGLShader* Shader)
{
	Shaders.erase(find(Shaders.begin(), Shaders.end(), Shader));
}


const std::vector<DGLShader*> DGLProgram::GetShaders()
{
	return this->Shaders;
}


void DGLProgram::Load()
{
	DResource::Load();
	this->ProgramID = glCreateProgram();
	for (auto &Shader : this->Shaders)
	{
		glAttachShader(this->ProgramID, Shader->GetShader());
	}
	glLinkProgram(this->ProgramID);

	GLint Result = GL_FALSE;
	int InfoLogLength;

	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);

	if (Result == GL_FALSE){
		std::vector<char> ProgramErrorMessage(std::max(InfoLogLength + 1, 1));
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		std::string __tmp(ProgramErrorMessage.begin(), ProgramErrorMessage.end());
		DApp::DF->DebugManager->Error(this, "Program Status: " + __tmp);
	}
}

void DGLProgram::Destroy()
{
	glDeleteProgram(this->ProgramID);
	DResource::Destroy();
}


GLuint DGLProgram::GetProgram()
{
	return this->ProgramID;
}
