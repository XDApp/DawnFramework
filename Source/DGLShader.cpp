#include "stdafx.h"
#include "DResourceLoader.h"
#include "DGLShader.h"
#include "DApp.h"
#include "DDebugManager.h"
#include "DStream.h"

DGLShader::DGLShader(DResourceLoader* loader)
	:DResource(loader),
	ShaderID(0),
	ShaderType(GL_SHADER)
{
}


DGLShader::~DGLShader()
{
}


void DGLShader::Load()
{
	DResource::Load();
	std::string ShaderString="";
	std::string Buffer;
	DStream* Stream = new DStream(this->Loader);
	while (Stream->Good())
	{
		ShaderString += Stream->Get();
	}
	delete Stream;

	GLint Result = GL_FALSE;
	int InfoLogLength;
	const char * ShaderCode = ShaderString.c_str();
	this->ShaderID = glCreateShader(this->ShaderType);

	glShaderSource(this->ShaderID, 1, &ShaderCode, NULL);
	glCompileShader(this->ShaderID);

	glGetShaderiv(this->ShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(this->ShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);

	if (Result == GL_FALSE){
		std::vector<char> ShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(this->ShaderID, InfoLogLength, NULL, &ShaderErrorMessage[0]);
		std::string __tmp(ShaderErrorMessage.begin(), ShaderErrorMessage.end());
		DApp::DF->DebugManager->Error(this, "Shader Status: " + __tmp);
	}
}


void DGLShader::Destroy()
{
	glDeleteShader(this->ShaderID);
	DResource::Destroy();
}


GLuint DGLShader::GetShader()
{
	return this->ShaderID;
}
