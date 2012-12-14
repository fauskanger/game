#pragma once
#include <SFML\Graphics.hpp>

#include <Windows.h>

#include <iostream>
#include <math.h>

#include "GridFloor.h"
#include "GridTileController.h"
#include "myMultiTextureAnimation.h"
#include "myAnimation.h"



#ifdef _DEBUG
	bool isDebug = true;
#else
	bool isDebug = false;
#endif