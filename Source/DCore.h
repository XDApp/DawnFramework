#pragma once

#define DClass(className) \
	public:\
	virtual const std::string ClassName() const{ return _StaticClassName(); }\
	static const std::string _StaticClassName(){ return (#className); }

#define DDel(objectName)\
	if(objectName != nullptr) delete objectName