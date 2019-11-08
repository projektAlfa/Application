#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include <coolDataTypes.h>
#include <sceneObject.h>
#include <rende.h>

class button
{
    public:
        button(SDL_Renderer* r,
               int wW, int wH);

        button(SDL_Renderer* r, bool v,
               int wW, int wH);

        button(SDL_Renderer* r,
               vector2D p, vector2D s,
               int wW, int wH);

        button(SDL_Renderer* r,
               vector2D p, vector2D s,
               bool v, int wW, int wH);

        ~button();

        sceneObject get();

        void getState(vector2D mPos, bool &clk, bool &hov);

    private:
        void            constructor(SDL_Renderer* r, int wW, int wH);

        SDL_Texture*    texA        = NULL;
        SDL_Texture*    texB        = NULL;
        sceneObject     sO;

        bool            hover       = false;
        bool            clicked     = false;
        bool            visible     = false;

        vector2D        siz         = {1.0, 1.0};
        vector2D        pos         = {0.5, 0.5};

        SDL_Color       borderCol1  = {150,200,255,128};
        SDL_Color       borderCol2  = {150,200,255,192};
        SDL_Color       fillCol1    = {240,240,240,255};
        SDL_Color       fillCol2    = {200,200,200,255};
};
#endif // BUTTON_H
