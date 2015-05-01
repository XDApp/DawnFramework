#pragma once

#define DClass(className) \
	public:\
	virtual const std::string ClassName() const{ return _StaticClassName(); }\
	static const std::string _StaticClassName(){ return (#className); }

#define DDel(objectName)\
	if(objectName) delete objectName

//Dawn Framework Color
using DColor = unsigned long;

//Dawn Framework Color ---> R G B A
#define DColorR(color) ((DColor)(((color)&(0xFF000000)) >> 24))
#define DColorG(color) ((DColor)(((color)&(0x00FF0000)) >> 16))
#define DColorB(color) ((DColor)(((color)&(0x0000FF00)) >> 8))
#define DColorA(color) ((DColor)((color)&(0x000000FF)))
#define DColorFloat(color)  (((float)(color))/255.0f)

//R G B A ---> Dawn Framework Color
#define DColorC(cR,cG,cB,cA) ((DColor)((cR<<24)|(cG<<16)|(cB<<8)|(cA)))

//Dawn Framework Color ---> OpenGL Color
#define DGCR(color) DColorFloat(DColorR(color))
#define DGCG(color) DColorFloat(DColorG(color))
#define DGCB(color) DColorFloat(DColorB(color))
#define DGCA(color) DColorFloat(DColorA(color))

GLEWContext* glewGetContext();
