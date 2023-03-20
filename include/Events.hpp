#include <SDL.h>
#pragma once
template<typename OutIt>
void SDL_push_events(OutIt out) {
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
		*out++ = e;
}