#include "button.h"

button::button(SDL_Renderer* r, int wW, int wH)
{
    constructor(r, wW, wH);
}

button::button(SDL_Renderer* r, bool v,
               int wW, int wH)
{
    visible = v;
    constructor(r, wW, wH);
}

button::button(SDL_Renderer* r,
               vector2D p, vector2D s,
               int wW, int wH)
{
    siz = s; pos = p;
    constructor(r, wW, wH);
}

button::button(SDL_Renderer* r,
               vector2D p, vector2D s,
               bool v, int wW, int wH)
{
    siz = s; pos = p; visible = v;
    constructor(r, wW, wH);
}

void button::constructor(SDL_Renderer* r, int wW, int wH)
{
    vector2DInt pS = {int(wW * siz.x), int(wH * siz.y)};

    texA = SDL_CreateTexture(r, SDL_PIXELFORMAT_ABGR8888,
                      SDL_TEXTUREACCESS_TARGET,
                      pS.x, pS.y);
    texB = SDL_CreateTexture(r, SDL_PIXELFORMAT_ABGR8888,
                      SDL_TEXTUREACCESS_TARGET,
                      pS.x, pS.y);

    SDL_SetRenderTarget(r, texA);

    rende::setDrawColor(r, fillCol1);
    SDL_RenderClear(r);

    rende::setDrawColor(r, borderCol1);
    SDL_Rect tR = {0, 0, pS.x - 1, pS.y - 1};
    SDL_RenderDrawRect(r, &tR);

    rende::setDrawColor(r, borderCol2);
    tR = {1, 1, pS.x - 1, pS.y - 1};
    SDL_RenderDrawRect(r, &tR);

    SDL_SetRenderTarget(r, texB);

    rende::setDrawColor(r, fillCol2);
    SDL_RenderClear(r);

    rende::setDrawColor(r, borderCol1);
    tR = {0, 0, pS.x - 1, pS.y - 1};
    SDL_RenderDrawRect(r, &tR);

    rende::setDrawColor(r, borderCol2);
    tR = {1, 1, pS.x - 1, pS.y - 1};
    SDL_RenderDrawRect(r, &tR);

    SDL_SetRenderTarget(r, NULL);

    sO.pos = {(pos.x - float(siz.x * 0.5)) * wW, (pos.y - float(siz.y * 0.5)) * wH};
    sO.siz = siz;
    sO.sRect = {0, 0, pS.x, pS.y};
    sO.texSiz = {pS.x, pS.y};
}

button::~button()
{
    if(texA != NULL)
        SDL_DestroyTexture(texA);
    if(texB != NULL)
        SDL_DestroyTexture(texB);
}

sceneObject button::get()
{
    if(hover || clicked)
        sO.texPtr = texB;
    else
        sO.texPtr = texA;

    return sO;
}

void button::getState(vector2D mPos, bool &clk, bool &hov)
{
    hov = false;

    if((mPos.x > pos.x - siz.x && mPos.x > pos.x + siz.x) && (mPos.y > pos.y - siz.y && mPos.y > pos.y + siz.y) )
        hov = true;

    clk = hov && clk;
}
