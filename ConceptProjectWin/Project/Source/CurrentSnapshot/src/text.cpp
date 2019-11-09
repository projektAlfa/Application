#include "text.h"

text::text(SDL_Renderer* r, std::string content, TTF_Font* ttF,
               vector2D p, bool c, SDL_Color col)
{
    SDL_Surface* tempSur = TTF_RenderText_Blended(ttF, content.c_str(), col);
    sO.texPtr = SDL_CreateTextureFromSurface(r, tempSur);

    p.x *= staticDef::winDim.x; p.y *= staticDef::winDim.y;
    sO.siz.x = 1.; sO.siz.y = 1.;


    sO.sRect = {0, 0, tempSur->w, tempSur->h};
    sO.texSiz = {tempSur->w, tempSur->h};
    if(c) sO.pos = {p.x - float(0.5 * sO.texSiz.x), p.y - float(0.5 * sO.texSiz.y)};
    else  sO.pos = p;

    SDL_FreeSurface(tempSur);
}

text::~text()
{
    if(sO.texPtr != NULL) SDL_DestroyTexture(sO.texPtr);
}

sceneObject text::get()
{
    return sO;
}

void text::changeContent(SDL_Renderer* r, std::string content, TTF_Font* ttF,
                         vector2D p, bool c, SDL_Color col)
{
    SDL_DestroyTexture(sO.texPtr);
    SDL_Surface* tempSur = TTF_RenderText_Blended(ttF, content.c_str(), col);
    sO.texPtr = SDL_CreateTextureFromSurface(r, tempSur);

    p.x *= staticDef::winDim.x; p.y *= staticDef::winDim.y;
    sO.siz.x = 1.; sO.siz.y = 1.;


    sO.sRect = {0, 0, tempSur->w, tempSur->h};
    sO.texSiz = {tempSur->w, tempSur->h};
    if(c) sO.pos = {p.x - float(0.5 * sO.texSiz.x), p.y - float(0.5 * sO.texSiz.y)};
    else  sO.pos = p;

    SDL_FreeSurface(tempSur);
}
