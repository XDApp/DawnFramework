#include "stdafx.h"
#include "DAppConfig.h"



DAppConfig::DAppConfig()
{
	char _Path[1024];
	GetCurrentDirectory(1024, _Path);
	this->__WorkPath.assign(_Path);
}


DAppConfig::~DAppConfig()
{
}


const std::string DAppConfig::WorkPath()
{
	return this->__WorkPath + "\\..\\";
}


const std::string DAppConfig::ResourcePath()
{
	return this->WorkPath() + "Resource\\";
}
