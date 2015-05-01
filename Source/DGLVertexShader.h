#pragma once
#include "DGLShader.h"

class DGLVertexShader :
	public DGLShader
{
	DClass(DGLVertexShader)
public:
	DGLVertexShader(DResourceLoader* loader);
	~DGLVertexShader();
};

