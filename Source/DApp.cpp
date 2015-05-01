#include "stdafx.h"
#include "DApp.h"

#include "DFramework.h"


DEngine *DApp::Engine;

DApp::DApp()
{
}


DApp::~DApp()
{
}


void DApp::Run()
{
	DApp::Engine = new DEngine();
	DApp::Engine->Initialize();

	DWindow *Window = DApp::Engine->WindowManager->NewWindow(800, 600, "Dawn Framework Sample Window");
	DApp::Engine->WindowManager->MakeCurrent(Window);
	DApp::Engine->InitializeContext();

	Window->Initialize();
	Window->Show();
	DApp::Engine->Loop();
}
