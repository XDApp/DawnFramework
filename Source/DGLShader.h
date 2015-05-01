#pragma once
#include "DResource.h"
#include "DTextFileResourceLoader.h"
class DGLShader :
	public DResource
{
	DClass(DGLShader)
public:
	DGLShader(DResourceLoader* loader);
	~DGLShader();
	DResource* Load();
	void Destroy();
};

