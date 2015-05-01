#include "stdafx.h"
#include "DApp.h"
#include "DAppConfig.h"
#include "DFramework.h"


DEngine *DApp::Engine;
DFrameworkReference* DApp::DF;

DApp::DApp()
{
}


DApp::~DApp()
{
}


void DApp::Run(DAppConfig* Config)
{
	DApp::Engine = new DEngine(Config);
	DApp::DF = new DFrameworkReference();
	DApp::DF->Clone(DApp::Engine->DF);

	DApp::Engine->Initialize();

	DWindow *Window = DApp::Engine->WindowManager->NewWindow(800, 600, "Dawn Framework Sample Window");
	DApp::Engine->WindowManager->MakeCurrent(Window);
	DApp::Engine->InitializeContext();
	Window->Show();

	Window->GraphicsManager->Debug_RunShader();
	DApp::Engine->Loop();
}
