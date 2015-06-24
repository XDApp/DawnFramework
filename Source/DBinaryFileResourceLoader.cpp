#include "stdafx.h"
#include "DBinaryFileResourceLoader.h"
#include "DApp.h"
#include "DFrameworkReference.h"
#include "DDebugManager.h"

DBinaryFileResourceLoader::DBinaryFileResourceLoader(const std::string filePath)
{
	this->Path = filePath;
	this->inStream = static_cast<std::istream*>(&this->fin);
}


DBinaryFileResourceLoader::~DBinaryFileResourceLoader()
{
}


const std::string DBinaryFileResourceLoader::GetPath() const
{
	return this->Path;
}


void DBinaryFileResourceLoader::Open()
{
	this->fin.open(Path, std::ios::in | std::ios::binary);
	if (!this->fin.is_open())
	{
		DApp::DF->DebugManager->Error(this, "Error Opening File: " + Path);
	}
}


void DBinaryFileResourceLoader::Close()
{
	this->fin.close();
}


void DBinaryFileResourceLoader::Buffer()
{
}
