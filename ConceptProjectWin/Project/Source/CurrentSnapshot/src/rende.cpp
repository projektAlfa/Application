#include "rende.h"

rende::rende(int S_w, int S_h, float S_S, logger* lH)
{
    logHndlr = lH;

    logHndlr->log("INFO: Engine initialization");

    WindowHeight = S_h * S_S;
    WindowWidth  = S_w * S_S;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        logHndlr->log("ERROR: Couldn't initialize SDL ( SDL_Init() )");
        wannaQuit = true;
    }
    else
    {
        logHndlr->log("INFO: SDL Initialized");

        if(TTF_Init() < 0)
            logHndlr->log("ERROR: Couldn't initialize TTF ( TTF_Init() )");
        else
            logHndlr->log("INFO: TTF Initialized");

        if(IMG_Init(IMG_INIT_PNG))
            logHndlr->log("ERROR: Couldn't initialize IMG_png ( IMG_Init() )");
        else
            logHndlr->log("INFO: IMG_png Initialized");

        wndw = SDL_CreateWindow("Koncept", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                WindowWidth, WindowHeight, SDL_WINDOW_SHOWN);
        if(wndw == NULL)
        {
            logHndlr->log("ERROR: SDL Couldn't create the window");
            wannaQuit = true;
        }
        else
        {
            logHndlr->log("INFO: SDL Window created");

            rnds = SDL_CreateRenderer(wndw, -1, SDL_RENDERER_ACCELERATED ||
                                      SDL_RENDERER_PRESENTVSYNC);
            if(rnds == NULL)
            {
                logHndlr->log("ERROR: SDL Couldn't create the renderer");
                wannaQuit = true;
            }
            else
                logHndlr->log("INFO: SDL renderer created");
        }
    }
}

rende::~rende()
{
    if(rnds != NULL)
    {
        SDL_DestroyRenderer(rnds);
        logHndlr->log("INFO: SDL renderer destroyed");
    }

    if(rnds != NULL)
    {
        SDL_DestroyWindow(wndw);
        logHndlr->log("INFO: SDL window destroyed");
    }

    logHndlr->log("INFO: SDL quitting");
    SDL_Quit();
    logHndlr->log("INFO: TTF quitting");
    TTF_Quit();
    logHndlr->log("INFO: IMG quitting");
    IMG_Quit();
    logHndlr->log("INFO: Engine shutdown");
}

void rende::eventHndlr()
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        switch(e.type)
        {
            case SDL_QUIT:
                wannaQuit = true;
                break;
        }
    }
}

void rende::consumeRenderStack()
{
    setDrawColor(backgroundCol);
    SDL_RenderClear(rnds);

    while(!renderStack.empty())
    {
        sceneObject currentObjToDraw = renderStack.top();

        SDL_Rect dRect = {int(currentObjToDraw.pos.x),    int(currentObjToDraw.pos.y),
                          int(currentObjToDraw.texSiz.x), int(currentObjToDraw.texSiz.y)};

        SDL_RenderCopy(rnds, currentObjToDraw.texPtr, &currentObjToDraw.sRect, &dRect);

        renderStack.pop();
    }
    SDL_RenderPresent(rnds);
}

bool rende::propWannaQuit(){return wannaQuit;}

void rende::setDrawColor(SDL_Color use)
{
    SDL_SetRenderDrawColor(rnds, use.r, use.g, use.b, use.a);
}

void rende::setDrawColor(SDL_Renderer* r, SDL_Color use)
{
    SDL_SetRenderDrawColor(r, use.r, use.g, use.b, use.a);
}

SDL_Renderer* rende::getRenderer()
{
    return rnds;
}

void rende::pushRenderStack(sceneObject toStack)
{
    renderStack.push(toStack);
}

mouseData rende::getTouch()
{
    mouseData m;
    return m;
}
