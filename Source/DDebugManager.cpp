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
}


void DDebugManager::Error(DawnEngineObject Sender, std::string Detail)
{
}
