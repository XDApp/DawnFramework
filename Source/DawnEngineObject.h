#pragma once

class DFrameworkReference;

class DawnEngineObject
{
public:
	DawnEngineObject();
	~DawnEngineObject();
	virtual const std::string ClassName() const = 0;

	DFrameworkReference* DF;
};
