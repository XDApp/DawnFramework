#include "stdafx.h"
#include "DStream.h"
#include "DResourceLoader.h"

DStream::DStream(DResourceLoader* loader)
	:Loader(loader),
	inStream(loader->Stream())
{
}


DStream::~DStream()
{
}


bool DStream::Good() const
{
	if (!inStream.good())Loader->Buffer();
	return inStream.good();
}


char DStream::Get()
{
	return inStream.get();
}
