#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <sstream>

#define GLEW_MX
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glfw3dll.lib")
#pragma comment (lib, "glu32.lib")
#pragma comment (lib, "glew32mxs.lib")



#include "DCore.h"
#include "DawnEngineObject.h"
#include "DFrameworkReference.h"