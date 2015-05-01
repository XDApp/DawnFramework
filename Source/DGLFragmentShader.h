#pragma once
#include "DGLShader.h"
class DGLFragmentShader :
	public DGLShader
{
	DClass(DGLFragmentShader)
public:
	DGLFragmentShader(DResourceLoader* loader);
	~DGLFragmentShader();
};

