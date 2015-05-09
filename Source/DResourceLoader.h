#pragma once
#include "DawnEngineObject.h"
class DResourceLoader :
	public DawnEngineObject
{
	DClass(DResourceLoader)
public:
	DResourceLoader();
	~DResourceLoader();
protected:
	std::istream *inStream;
public:
	virtual void Open() = 0;
	virtual std::istream& Stream() const;
	virtual void Close() = 0;
};
