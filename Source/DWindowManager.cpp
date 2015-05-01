#include "stdafx.h"
#include "DWindow.h"
#include "DDebugManager.h"
#include "DWindowManager.h"
#include "DApp.h"
#include "DEngine.h"

DWindowManager::DWindowManager()
	: CurrentWindow(nullptr)
{
}


DWindowManager::~DWindowManager()
{
}


DWindow* DWindowManager::NewWindow(int Width, int Height, std::string Title)
{
	DWindow *Window = new DWindow(AllocWindowObject(Width, Height, Title));
	Window->DF->Window = Window;
	Window->PullReference(this);

	
	glewExperimental = GL_TRUE;
	Window->Context = new GLEWContext();

	this->MakeCurrent(Window);

	if (Window->Context == nullptr)
	{
		DF->DebugManager->Error(this, "Failed to Create GLEW Context");
		return nullptr;
	}
	
	if (glewInit() != GLEW_OK)
	{
		DF->DebugManager->Error(this, "Failed to Initialize GLEW");
		return nullptr;
	}
	else
	{
		DF->DebugManager->Message(this, "GLEW is Initialized Successfully");
	}
	Window->Initialize();

	this->Windows.push_back(Window);
	return Window;
}


GLFWwindow* DWindowManager::AllocWindowObject(int Width, int Height, std::string Title)
{
	DWindow *__Window = this->__GetAllocedWindow();
	GLFWwindow *___Window = __Window == nullptr ? nullptr : __Window->GetWindow();
	GLFWwindow* Window = glfwCreateWindow(Width, Height, Title.c_str(), nullptr, ___Window);
	if (Window == nullptr){
		glfwTerminate();
		this->DF->DebugManager->Error(this, "Window Create Failed");
		return nullptr;
	}
	glfwSetInputMode(Window, GLFW_STICKY_KEYS, GL_TRUE);
	return Window;
}


void DWindowManager::DestroyWindow(DWindow* Window)
{
	delete Window->Context;
	this->Windows.erase(std::find(Windows.begin(), Windows.end(), Window));
	DestroyWindowObject(Window->GetWindow());
}

void DWindowManager::DestroyWindowObject(GLFWwindow* Window)
{
	glfwDestroyWindow(Window);
}


void DWindowManager::Initialize()
{
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_VISIBLE, 0);
	glfwWindowHint(GLFW_RESIZABLE, 0);
}


void DWindowManager::MakeCurrent(DWindow* Window)
{
	if (Window != this->CurrentWindow)
	{
		if(Window!=nullptr)glfwMakeContextCurrent(Window->GetWindow());
		else glfwMakeContextCurrent(nullptr);
		CurrentWindow = Window;
	}
}

void DWindowManager::Render()
{
	for (auto Window : Windows)
	{
		this->MakeCurrent(Window);
		Window->Render();
	}
}

void DWindowManager::Update()
{
	this->ProcessCloseSignal();
	glfwPollEvents();
	
	for (auto Window : Windows)
	{
		this->MakeCurrent(Window);
		Window->Update();
	}
}


bool DWindowManager::HasWindowAvailable()
{
	return !Windows.empty();
}

void DWindowManager::CloseWindow(DWindow* Window)
{
	this->CloseWindowQueue.push_back(Window);
}


void DWindowManager::ProcessCloseSignal()
{
	while (!this->CloseWindowQueue.empty())
	{
		this->DestroyWindow(this->CloseWindowQueue.back());
		this->CloseWindowQueue.pop_back();
	}
}


void DWindowManager::PullReference(const DawnEngineObject* Object)
{
	DawnEngineObject::PullReference(Object);
	for (auto &Window : Windows)
	{
		Window->PullReference(this);
	}
}


GLEWContext* glewGetContext()
{
	return DApp::Engine->WindowManager->GetCurrentWindow()->GetContext();
}

DWindow* DWindowManager::GetCurrentWindow()
{
	return this->CurrentWindow;
}

DWindow* DWindowManager::__GetAllocedWindow()
{
	if (this->Windows.empty())return nullptr;
	else return this->Windows[0];
}