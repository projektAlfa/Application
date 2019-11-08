#ifndef COOLDATATYPES_H
#define COOLDATATYPES_H

#include <SDL2/SDL.h>

struct vector2D
{
    float x, y;
};

struct vector2DInt
{
    int x, y;
};

struct Dimage
{
    int x, y;
    SDL_Texture* pic;
};

struct mouseData
{
    vector2D pos;
    bool touch;
};
#endif
