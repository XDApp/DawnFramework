#include "stdafx.h"
#include "DResourceLoader.h"

DResourceLoader::DResourceLoader()
{
}


DResourceLoader::~DResourceLoader()
{
}


std::istream& DResourceLoader::Stream() const
{
	return *(this->inStream);
}
