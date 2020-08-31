// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#include "framework.h"

#include "Core/Assert.h"

#include "Math/Math.h"
#include "Math/Color.h"
#include "Math/Random.h"
#include "Math/Transform.h"

#include "Objects/ObjectFactory.h"

#include <SDL.h>
#include <SDL_image.h>

#include <map>
#include <list>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include <cassert>
#include <iostream>
#include <functional>

#endif //PCH_H
