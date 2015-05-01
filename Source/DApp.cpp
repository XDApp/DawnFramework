#include "stdafx.h"
#include "DApp.h"
#include "DAppConfig.h"
#include "DScene_Main.h"
#include "DScene_Main2.h"
#include "DFramework.h"
#include "DSceneManager.h"


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
	DWindow *Window2 = DApp::Engine->WindowManager->NewWindow(800, 600, "Dawn Framework Second Window");
	DWindow *Window3 = DApp::Engine->WindowManager->NewWindow(800, 600, "Dawn Framework Third Window");
	DWindow *Window4 = DApp::Engine->WindowManager->NewWindow(800, 600, "Dawn Framework Fourth Window");

	Window->Show();
	Window2->Show();
	Window3->Show();
	Window4->Show();

	Window->GraphicsManager->SceneManager->PushSceneObject(new DScene_Main());
	Window2->GraphicsManager->SceneManager->PushSceneObject(new DScene_Main());
	Window3->GraphicsManager->SceneManager->PushSceneObject(new DScene_Main2());
	Window4->GraphicsManager->SceneManager->PushSceneObject(new DScene_Main2());

	DApp::Engine->Loop();
}
