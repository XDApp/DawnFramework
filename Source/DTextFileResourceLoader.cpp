#include "stdafx.h"
#include "DApp.h"
#include "DDebugManager.h"
#include "DTextFileResourceLoader.h"


DTextFileResourceLoader::DTextFileResourceLoader(const std::string filePath)
{
	this->Path = filePath;
	this->inStream = static_cast<std::istream*>(&this->fin);
}


DTextFileResourceLoader::~DTextFileResourceLoader()
{
}


const std::string DTextFileResourceLoader::GetPath() const
{
	return this->Path;
}


void DTextFileResourceLoader::Open()
{
	this->fin.open(Path, std::ifstream::in);
	if (!this->fin.is_open())
	{
		DApp::DF->DebugManager->Error(this, "Error Opening File: " + Path);
	}
}


void DTextFileResourceLoader::Close()
{
	this->fin.close();
}


void DTextFileResourceLoader::Buffer()
{
}
