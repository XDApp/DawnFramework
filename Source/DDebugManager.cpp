#include "stdafx.h"
#include "DDebugManager.h"


DDebugManager::DDebugManager()
{
}


DDebugManager::~DDebugManager()
{
}


void DDebugManager::DebugPrint(const std::string& DebugString)
{
	std::cout << DebugString << std::endl;
	OutputDebugString((DebugString + "\n").c_str());
}

void DDebugManager::Error(const DawnEngineObject* Sender, const std::string& Detail)
{
	this->ClassPrint(Sender, "Error: " + Detail);
}


void DDebugManager::Message(const DawnEngineObject* Sender, const std::string& Detail)
{
	this->ClassPrint(Sender, "Message: " + Detail);
}

void DDebugManager::ClassPrint(const DawnEngineObject* Sender, const std::string& Detail)
{
	this->DebugPrint("[" + Sender->ClassName() + "] " + Detail);
}
