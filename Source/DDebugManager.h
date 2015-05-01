#pragma once
#include "DawnEngineObject.h"

class DDebugManager :
	public DawnEngineObject
{
	DClass(DDebugManager)
public:
	DDebugManager();
	~DDebugManager();
	

	void DebugPrint(const std::string& DebugString);
	void Error(const DawnEngineObject* Sender, const std::string& Detail);
	void Message(const DawnEngineObject* Sender, const std::string& Detail);

	void ClassPrint(const DawnEngineObject* Sender, const std::string& Detail);
};

