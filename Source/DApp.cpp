#include "stdafx.h"
#include "DApp.h"
#include "DAppConfig.h"
#include "DFramework.h"


DEngine *DApp::Engine;

DApp::DApp()
{
}


DApp::~DApp()
{
}


void DApp::Run(DAppConfig* Config)
{
	DApp::Engine = new DEngine(Config);
	DApp::Engine->Initialize();

	DWindow *Window = DApp::Engine->WindowManager->NewWindow(800, 600, "Dawn Framework Sample Window");
	DApp::Engine->WindowManager->MakeCurrent(Window);
	DApp::Engine->InitializeContext();

	Window->Initialize();
	Window->Show();
	DApp::Engine->Loop();
}
