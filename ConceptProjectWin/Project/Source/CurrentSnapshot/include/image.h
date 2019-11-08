#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <coolDataTypes.h>
#include <sceneObject.h>

class image
{
    public:
        image(SDL_Renderer* r, std::string url,
               vector2D p, float scale, bool c,
               int wW, int wH);
        ~image();
        sceneObject get();
        sceneObject sO;
};
#endif // IMAGE_H
