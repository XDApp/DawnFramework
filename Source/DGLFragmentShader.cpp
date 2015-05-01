#include "stdafx.h"
#include "DGLFragmentShader.h"


DGLFragmentShader::DGLFragmentShader(DResourceLoader* loader)
	:DGLShader(loader)
{
	this->ShaderType = GL_FRAGMENT_SHADER;
}


DGLFragmentShader::~DGLFragmentShader()
{
}
