#include "stdafx.h"
#include "DDebugManager.h"


DDebugManager::DDebugManager()
{
}


DDebugManager::~DDebugManager()
{
}


void DDebugManager::DebugPrint(std::string DebugString)
{
	std::cout << DebugString << std::endl;
	OutputDebugString((DebugString + "\n").c_str());
}


void DDebugManager::Error(DawnEngineObject* Sender, std::string Detail)
{
	this->DebugPrint(Detail);
}


void DDebugManager::Message(DawnEngineObject* Sender, std::string Detail)
{
	this->DebugPrint(Detail);
}
