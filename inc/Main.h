#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>

#include <Windows.h>

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

#include "Globals.h"
#include "GridTileController.h"
#include "GridFloor.h"
#include "myMultiTextureAnimation.h"
#include "myAnimation.h"



#ifdef _DEBUG
	bool isDebug = true;
#else
	bool isDebug = false;
#endif

static const double PI = 3.14159265;