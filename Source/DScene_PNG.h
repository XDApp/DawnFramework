#pragma once
#include "DScene.h"

class DScene_PNG :
	public DScene
{
	DClass(DScene_PNG)
public:
	DScene_PNG();
	~DScene_PNG();
	void Update();
	void Render();
	void Start();
	void End();
};

