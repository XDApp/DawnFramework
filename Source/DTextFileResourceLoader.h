#pragma once
#include "DResourceLoader.h"
class DTextFileResourceLoader :
	public DResourceLoader
{
	DClass(DTextFileResourceLoader)
protected:
	std::string Path;
public:
	DTextFileResourceLoader(const std::string filePath);
	~DTextFileResourceLoader();
	const std::string GetPath() const;
protected:
	std::ifstream fin;
public:
	virtual void Open();
	virtual void Close();
	virtual void Buffer();
};

