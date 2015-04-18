#pragma once

class DDebugManager :
	public DawnEngineObject
{
public:
	DDebugManager();
	~DDebugManager();
	void DebugPrint(std::string DebugString);
	void Error(DawnEngineObject Sender, std::string Detail);
};

