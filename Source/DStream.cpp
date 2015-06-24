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

std::streamsize DStream::Read(char* Target, std::streamsize Length)
{
	this->inStream.read(Target, Length);
	if (this->inStream.good())return Length;
	else return this->inStream.gcount();
}
