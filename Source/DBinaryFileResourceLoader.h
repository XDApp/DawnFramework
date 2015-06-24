#pragma once
#include "DResourceLoader.h"

class DBinaryFileResourceLoader :
	public DResourceLoader
{
	DClass(DBinaryFileResourceLoader)
protected:
	std::string Path;
public:
	DBinaryFileResourceLoader(const std::string filePath);
	~DBinaryFileResourceLoader();
	const std::string GetPath() const;
protected:
	std::ifstream fin;
public:
	virtual void Open();
	virtual void Close();
	virtual void Buffer();
};

