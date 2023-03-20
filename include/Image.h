#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#pragma once
#ifndef SIMPLE_GAME_ENGINE_GRAPHICS
#define SIMPLE_GAME_ENGINE_GRAPHICS
#endif

SDL_Surface* SDL_loadMedia(const char* file)
{
    //Load splash image
    SDL_Surface* image = SDL_LoadBMP(file);
    if (image == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", file, SDL_GetError());
    }

    return image;
}

SDL_Surface* SDL_CreateSurface(int width, int height)
{
    uint32_t rmask, gmask, bmask, amask;

    /* SDL interprets each pixel as a 32-bit number, so our masks must depend
       on the endianness (byte order) of the machine */
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
#else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
#endif

    SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, rmask, gmask, bmask, amask);
    if (surface == NULL)
    {
        (void)fprintf(stderr, "CreateRGBSurface failed: %s\n", SDL_GetError());
        exit(1);
    }

    return surface;
}