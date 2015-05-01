#include "stdafx.h"
#include "DTextFileResourceLoader.h"


DTextFileResourceLoader::DTextFileResourceLoader(const std::string filePath)
{
	this->Path = filePath;
	this->inStream = static_cast<std::istream*>(&this->fin);
}


DTextFileResourceLoader::~DTextFileResourceLoader()
{
}


const std::string DTextFileResourceLoader::GetPath()
{
	return this->Path;
}


void DTextFileResourceLoader::Open()
{
	this->fin.open(Path, std::ifstream::in);
}


void DTextFileResourceLoader::Close()
{
	this->fin.close();
}
