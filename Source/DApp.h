#pragma once

class DApp
{
	DClass(DApp)
public:
	static DEngine *Engine;
	DApp();
	virtual ~DApp();
	static void Run(DAppConfig* Config);
	static DFrameworkReference* DF;
};
