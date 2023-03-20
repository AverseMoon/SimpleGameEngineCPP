#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Vector.hpp"
#include "Node.hpp"
using namespace SGE_UTIL;
using namespace SGE_NODES;
#pragma once
#ifndef SIMPLE_GAME_ENGINE_GRAPHICS
#define SIMPLE_GAME_ENGINE_GRAPHICS
#endif

namespace SGE_GRAPHICS {
	class Camera {
	public:
		Vec2 pos;
		Vec2 size = Vec2(1,1);
	};
	class Renderer {
	public:
		NODE2D root = NODE2D();
		Camera camera;
		Renderer(Vec2 CameraPos = Vec2(), Vec2 CameraSize = Vec2(1,1)) {
			camera.pos = CameraPos;
		}
		void render(SDL_Renderer* renderer) {
			root.refreshPosition(camera.pos);
			root.refreshSize(camera.size);
			root.RENDER(renderer);
		}
	};
}