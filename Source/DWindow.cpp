#include "stdafx.h"
#include "DWindow.h"

DWindow::DWindow(GLFWwindow* Window)
	:gWindow(Window)
{
}


DWindow::~DWindow()
{
}


GLFWwindow* DWindow::GetWindow()
{
	return this->gWindow;
}
