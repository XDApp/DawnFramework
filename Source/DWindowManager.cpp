#include "stdafx.h"
#include "DWindow.h"
#include "DDebugManager.h"
#include "DWindowManager.h"


DWindowManager::DWindowManager()
	: CurrentWindow(nullptr)
{
}


DWindowManager::~DWindowManager()
{
	delete DF;
}


DWindow* DWindowManager::NewWindow(int Width, int Height, std::string Title)
{
	DWindow *Window = new DWindow(AllocWindowObject(Width, Height, Title));
	Window->DF->Engine = this->DF->Engine;
	Window->DF->WindowManager = this->DF->WindowManager;
	Window->DF->DebugManager = this->DF->DebugManager;
	Window->DF->Window = Window;

	this->Windows.push_back(Window);
	return Window;
}


GLFWwindow* DWindowManager::AllocWindowObject(int Width, int Height, std::string Title)
{
	GLFWwindow* Window = glfwCreateWindow(Width, Height, Title.c_str(), nullptr, nullptr);
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
	//glfwWindowHint(GLFW_VISIBLE, 0);
	glfwWindowHint(GLFW_RESIZABLE, 0);
}


void DWindowManager::MakeCurrent(DWindow* Window)
{
	glfwMakeContextCurrent(Window->GetWindow());
	CurrentWindow = Window;
}

void DWindowManager::Render()
{
	for (auto &Window : Windows)
	{
		this->MakeCurrent(Window);
		Window->Render();
		glfwSwapBuffers(CurrentWindow->GetWindow());
		glfwPollEvents();
	}
}

bool DWindowManager::Update()
{
	for (auto &Window : Windows)
	{
		Window->Update();
	}
	this->ProcessCloseSignal();
	return this->HasWindowAvailable();
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
