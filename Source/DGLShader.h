#pragma once
#include "DResource.h"
#include "DTextFileResourceLoader.h"

class DGLShader :
	public DResource
{
	DClass(DGLShader)
public:
	~DGLShader();
	void Load();
	void Destroy();
protected:
	GLenum ShaderType;
	DGLShader(DResourceLoader* loader);
	GLuint ShaderID;
public:
	GLuint GetShader();
};
