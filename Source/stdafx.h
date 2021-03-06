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
#include <lpng/png.h>
#include <zlib/zconf.h>
#include <zlib/zlib.h>

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glfw3.lib")
#pragma comment (lib, "glew32mxs.lib")
#pragma comment (lib, "zlib.lib")
#pragma comment (lib, "libpng16.lib")

#include "DCore.h"
#include "DawnEngineObject.h"
#include "DFrameworkReference.h"