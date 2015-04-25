#pragma once

class DFrameworkReference;

class DawnEngineObject
{
	DClass(DawnEngineObject)
public:
	DawnEngineObject();
	~DawnEngineObject();
	
	DFrameworkReference* DF;
};
