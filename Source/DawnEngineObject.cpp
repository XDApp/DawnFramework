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


void DawnEngineObject::PullReference(const DawnEngineObject* Object)
{
	this->DF->Clone(Object->DF);
}
