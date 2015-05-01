#include "stdafx.h"
#include "DResource.h"
#include "DResourceLoader.h"

DResource::DResource(DResourceLoader* loader)
	:Loader(loader),
	__isLoad(false)
{
}


DResource::~DResource()
{
}


bool DResource::isLoad()
{
	return this->__isLoad;
}

void DResource::Load()
{
	__isLoad = true;
}

void DResource::Destroy()
{
	__isLoad = false;
}