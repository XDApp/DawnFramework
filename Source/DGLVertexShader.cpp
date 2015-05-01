#include "stdafx.h"
#include "DGLVertexShader.h"


DGLVertexShader::DGLVertexShader(DResourceLoader* loader)
	: DGLShader(loader)
{
	this->ShaderType = GL_VERTEX_SHADER;
}


DGLVertexShader::~DGLVertexShader()
{
}
