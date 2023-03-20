// SIMPLE GAME ENGINE //

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_Main.h>
#include <iostream>
#include <stdio.h>
#include "Image.h"
#include "Node.h"
#include "Render.h"
#include "Screen.h"
#include "Vector.h"
#pragma once
using namespace std;


#ifndef SIMPLE_GAME_ENGINE_CORE
#define SIMPLE_GAME_ENGINE_CORE
#endif

const float SIMPLE_GAME_ENGINE_VERSION = 0.0;


namespace SGE_CORE {
	bool SGE_Init(Uint32 initFlags = SDL_INIT_EVERYTHING) {
		int ret = SDL_Init(initFlags);
		if (ret < 0) {
			printf("Simple Game Engine -> SDL2 Failed to load, ERROR: %s", SDL_GetError());
			return false;
		}
		else {
			printf("Simple Game Engine -> SDL2 Initialized\n");
		}
		return true;
	}
}