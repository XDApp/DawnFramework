#pragma once
#include "DResource.h"

class DGLShader;

class DGLProgram :
	public DResource
{
	DClass(DGLProgram)
public:
	DGLProgram();
	~DGLProgram();
	void AttachShader(DGLShader* Shader);
	void DetachShader(DGLShader* Shader);
protected:
	std::vector<DGLShader*> Shaders;
	GLuint ProgramID;
public:
	const std::vector<DGLShader*> GetShaders() const;
	void Load();
	void Destroy();
public:
	GLuint GetProgram();
};

