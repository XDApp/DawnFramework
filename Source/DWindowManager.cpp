#include "stdafx.h"
#include "DWindowManager.h"


DWindowManager::DWindowManager()
	: CurrentWindow(NULL)
{
}


DWindowManager::~DWindowManager()
{
}


GLFWwindow* DWindowManager::NewWindow(int Width, int Height, std::string Title)
{
	GLFWwindow *Window = AllocWindowObject(Width, Height, Title);
	glfwSetInputMode(Window, GLFW_STICKY_KEYS, GL_TRUE);
	return Window;
}


GLFWwindow* DWindowManager::AllocWindowObject(int Width, int Height, std::string Title)
{
	GLFWwindow* Window = glfwCreateWindow(Width, Height, Title.c_str(), nullptr, nullptr);
	if (Window == nullptr){
		glfwTerminate();
		//DEBUG
		return nullptr;
	}
	this->Windows.push_back(Window);
	return Window;
}


void DWindowManager::DestroyWindowObject(GLFWwindow* Window)
{
	this->Windows.erase(std::find(Windows.begin(), Windows.end(), Window));
	glfwDestroyWindow(Window);
}


void DWindowManager::Initialize()
{
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}


void DWindowManager::MakeCurrent(GLFWwindow* Window)
{
	glfwMakeContextCurrent(Window);
	CurrentWindow = Window;
}


void DWindowManager::Loop()
{
	PreLoop();
	Update();
	PostLoop();
}


void DWindowManager::PreLoop()
{
	for (auto &Window : Windows)
	{
		this->MakeCurrent(Window);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	}
}


void DWindowManager::PostLoop()
{
	glfwTerminate();
}


void DWindowManager::Update()
{
	std::vector<GLFWwindow*> ShouldClose;

	do{
		for (auto &Window : Windows)
		{
			this->MakeCurrent(Window);

			glfwSwapBuffers(CurrentWindow);
			glfwPollEvents();
			if (glfwWindowShouldClose(CurrentWindow))
			{
				ShouldClose.push_back(CurrentWindow);
			}
		}
		while (!ShouldClose.empty())
		{
			DestroyWindowObject(ShouldClose.back());
			ShouldClose.pop_back();
		}
	} while (this->HasWindowAvailable());

}


bool DWindowManager::HasWindowAvailable()
{
	return !Windows.empty();
}
