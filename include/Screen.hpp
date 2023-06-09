#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Vector.hpp"
#include <iostream>
#include <list>
#include "Render.hpp"
#include "Events.hpp"
#include "Image.hpp"
#include <windows.h>
#pragma once
using namespace std;
using namespace SGE_UTIL;
using namespace SGE_GRAPHICS;

#ifndef SIMPLE_GAME_ENGINE_GRAPHICS
#define SIMPLE_GAME_ENGINE_GRAPHICS
#endif

namespace SGE_GRAPHICS {
	class Window;
	typedef int (*draw_function_type)(list<SDL_Event> events, Window* window);

	class Window {
	public:
		SDL_Window* window = NULL;
		Vec2i WindowSize;
		Vec2i WindowPos;
		list <draw_function_type> drawFunctions;
		Renderer spriteRenderer = Renderer();
		SDL_Renderer* renderer = NULL;
		Uint64 tick = 0;

		void AddChild(NODETYPE node) { spriteRenderer.root.addChild(node); }
		void AddDrawFunction(draw_function_type function) { drawFunctions.push_back(function); }
		void Destroy() { SDL_DestroyWindow(window); window = NULL; }
		void setTitle(const char* title) { SDL_SetWindowTitle(window, title); }
		void setIcon(const char* file) { SDL_SetWindowIcon(window, SDL_loadMedia(file)); }
		int Run() {
			bool quit = false;
			tick = 0;
			while (!quit) {
				SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
				SDL_RenderClear(renderer);
				list<SDL_Event> events;
				SDL_push_events(back_inserter(events));
				for (const SDL_Event& e : events) {
					if (e.type == SDL_QUIT) {
						Destroy();
						quit = true;
						return 0;
					}
					else if (e.type == SDL_WINDOWEVENT_RESIZED) {
						SDL_SetWindowSize(window, e.window.data1, e.window.data2);
					}
				}
				for (draw_function_type func : drawFunctions) {
					if (func(events, this)) {
						quit = true;
					}
				}
				spriteRenderer.render(renderer);
				tick++;
			}
			return 0;
		}
		Window(Vec2 pos = Vec2(), Vec2 size = Vec2(500, 500), const char* title = "Simple Game", const char* icon = "icon.bmp", Uint32 initFlags = SDL_INIT_EVERYTHING, Uint32 windowFlags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN) {
			WindowSize = Vec2i(size);
			WindowPos = Vec2i(pos);
			window = SDL_CreateWindow(title, WindowPos.x, WindowPos.y, WindowSize.x, WindowSize.y, windowFlags);
			if (window == NULL) {
				cout << "Window could not be created, ERROR: " << SDL_GetError() << "\n";
			}
			else {
				renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
				if (renderer == NULL) {
					cout << "Renderer could not be created, ERROR: " << SDL_GetError() << "\n";
				}
				else {
					SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
					setIcon(icon);
				}
			};
		}
	};
}