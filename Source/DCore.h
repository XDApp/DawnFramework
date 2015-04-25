#pragma once

#define DClass(className) \
	public:\
	virtual const std::string ClassName(){ return _StaticClassName(); }\
	static const std::string _StaticClassName(){ return (#className); }