#include "stdafx.h"
#include "DawnEngineObject.h"

DawnEngineObject::DawnEngineObject()
	:DF(new DFrameworkReference)
{
}


DawnEngineObject::~DawnEngineObject()
{
	DDel(this->DF);
}
