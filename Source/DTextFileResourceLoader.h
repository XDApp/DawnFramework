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
	const std::string GetPath();
protected:
	std::ifstream fin;
public:
	virtual void Open();
	virtual void Close();
};

