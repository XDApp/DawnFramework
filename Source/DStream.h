#pragma once
#include "DawnEngineObject.h"

class DResourceLoader;

class DStream :
	public DawnEngineObject
{
	DClass(DStream)
protected:
	DResourceLoader* Loader;
	std::istream& inStream;
public:
	DStream(DResourceLoader* loader);
	~DStream();
	bool Good() const;
	char Get();
	std::streamsize Read(char* Target, std::streamsize Length);
};

