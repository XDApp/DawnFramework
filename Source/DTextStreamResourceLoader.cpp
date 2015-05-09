#include "stdafx.h"
#include "DTextStreamResourceLoader.h"


DTextStreamResourceLoader::DTextStreamResourceLoader(const std::string& strStream)
	:sStream(strStream)
{
	this->inStream = static_cast<std::istream*>(&this->sin);
}


DTextStreamResourceLoader::~DTextStreamResourceLoader()
{
}

void DTextStreamResourceLoader::Open()
{
	sin << sStream;
}


void DTextStreamResourceLoader::Close()
{
	sin.clear();
}


void DTextStreamResourceLoader::Buffer()
{
}
