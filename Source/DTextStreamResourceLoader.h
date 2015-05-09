#pragma once
#include "DResourceLoader.h"
class DTextStreamResourceLoader :
	public DResourceLoader
{
	DClass(DTextStreamResourceLoader)
public:
	DTextStreamResourceLoader(const std::string& strStream);
	~DTextStreamResourceLoader();
protected:
	std::stringstream sin;
	const std::string sStream;
public:
	virtual void Open();
	virtual void Close();
	virtual void Buffer();
};

