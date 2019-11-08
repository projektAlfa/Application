#ifndef RENDE_H
#define RENDE_H

#include <staticDef.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <logger.h>
#include <sceneObject.h>
#include <vector>
#include <stack>
#include <fstream>
#include <string>
#include <iostream>
#include <coolDataTypes.h>
#include <button.h>
#include <text.h>
#include <image.h>

class rende
{
    public:
        rende(int S_w, int S_h, float S_S, logger* lH);
        ~rende();

        void eventHndlr();
        void consumeRenderStack();
        bool propWannaQuit();
        void setDrawColor(SDL_Color use);
        static void setDrawColor(SDL_Renderer* r,
                                 SDL_Color use);
        SDL_Renderer* getRenderer();
        void pushRenderStack(sceneObject toStack);
        mouseData getTouch();

    private:
        logger*                     logHndlr        = NULL;

        SDL_Renderer*               rnds            = NULL;
        SDL_Window*                 wndw            = NULL;
        SDL_Color                   backgroundCol   = {255, 255,
                                                       255, 255};
        SDL_Color                   defaultTexCol   = {  0,   0,
                                                         0, 255};
        int                         IDLast          = -1;
        int                         WindowHeight    = 0;
        int                         WindowWidth     = 0;

        bool                        wannaQuit       = false;

        std::stack<sceneObject>     renderStack;
        std::vector<Dimage>         Images;
};

#endif // RENDE_H
