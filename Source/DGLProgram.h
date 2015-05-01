#pragma once
#include "DResource.h"
class DGLProgram :
	public DResource
{
	DClass(DGLProgram)
public:
	DGLProgram(DResourceLoader* loader);
	~DGLProgram();
};

