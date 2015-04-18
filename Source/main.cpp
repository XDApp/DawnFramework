#include "stdafx.h"

#include "DApp.h"
#include "DEngine.h"

int main()
{
	DApp::Engine = new DEngine();
	DApp::Engine->Initialize();
	DApp::Engine->WindowManager->NewWindow(640, 480, "Dawn Framework");
	DApp::Engine->WindowManager->NewWindow(640, 480, "Dawn Framework 2");
	DApp::Engine->WindowManager->MakeCurrent(DApp::Engine->WindowManager->NewWindow(640, 480, "Dawn Framework 3"));
	DApp::Engine->Loop();
	return 0;
}