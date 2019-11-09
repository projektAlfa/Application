#include "image.h"

image::image(SDL_Renderer* r, std::string url,
               vector2D p, float scale, bool c)
{
    SDL_Surface* tempSur = IMG_Load(url.c_str());
    sO.texPtr = SDL_CreateTextureFromSurface(r, tempSur);

    p.x *= staticDef::winDim.x; p.y *= staticDef::winDim.y;
    sO.siz.x = scale; sO.siz.y = scale;

    sO.sRect = {0, 0, tempSur->w, tempSur->h};
    sO.texSiz = {tempSur->w, tempSur->h};
    if(c) sO.pos = {p.x - float(0.5 * sO.texSiz.x * sO.siz.x), p.y - float(0.5 * sO.texSiz.y * sO.siz.y)};
    else  sO.pos = p;

    SDL_FreeSurface(tempSur);
}

image::~image()
{
    if(sO.texPtr != NULL) SDL_DestroyTexture(sO.texPtr);
}

sceneObject image::get()
{
    return sO;
}
