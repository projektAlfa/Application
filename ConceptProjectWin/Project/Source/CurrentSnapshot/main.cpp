#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <rende.h>
#include <logger.h>
#include <cmath>
#include <string>
#include <windows.h>

//Screen dimension constants
const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 1280;
const float SCREEN_SCALE = 0.5;

int main(int argc, char* args[])
{
    logger log;

    rende* gfx = new rende(SCREEN_WIDTH,
                           SCREEN_HEIGHT,
                           SCREEN_SCALE,
                           &log);

    staticDef::winDim.x = SCREEN_WIDTH * SCREEN_SCALE;
    staticDef::winDim.y = SCREEN_HEIGHT * SCREEN_SCALE;

    //gfx->addImage("logotype");

    TTF_Font* font1 = TTF_OpenFont("C:/Windows/Fonts/calibri.ttf", 24);
    //TTF_Font* font2 = TTF_OpenFont("C:/Windows/Fonts/ariblk.ttf", 18);
    TTF_Font* font3 = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 12);

    bool screen1 = true, screen2 = false, screen3 = false;


    while(!gfx->propWannaQuit())
    {
        //Splash Screen
        if(screen1)
        {
            button enterBut(gfx->getRenderer(),
                            {0.5, 0.8}, {0.5, 0.05}, true);

            text   splashTxt(gfx->getRenderer(), "Poli::Map", font1,
                             {0.5, 0.75}, true, {255,200,150,255});

            image  splashImg(gfx->getRenderer(), "./Data/Image/logotype.bmp",
                             {0.5, 0.5} , 1.0, true);

            text   mouseTextX(gfx->getRenderer(), "mouse x: ", font3,
                              {0.01, 0.005}, false, {0,0,0,255});

            text   mouseTextY(gfx->getRenderer(), "mouse y: ", font3,
                              {0.01, 0.01}, false, {0,0,0,255});

            text   buttTextHov(gfx->getRenderer(), "button hover: ", font3,
                               {0.01, 0.015}, false, {0,0,0,255});

            text   buttTextClk(gfx->getRenderer(), "button click: ", font3,
                               {0.01, 0.020}, false, {0,0,0,255});

            int i = 0;

            while(!gfx->propWannaQuit() && screen1)
            {
                gfx->pushRenderStack(mouseTextX.get());
                gfx->pushRenderStack(mouseTextY.get());
                //gfx->pushRenderStack(splashImg.get());
                gfx->pushRenderStack(splashTxt.get());
                gfx->pushRenderStack(enterBut.get());
                gfx->pushRenderStack(buttTextHov.get());
                gfx->pushRenderStack(buttTextClk.get());
                gfx->consumeRenderStack();

                bool butClk, butHov;

                mouseData mD = gfx->getTouch();
                butClk = mD.touch;

                splashImg.sO.moveG({0.5, float(0.5 + 0.01 * sin(i/5000. * M_PI))}, true);
                splashImg.sO.scaleG(1. + sin(i/2500. * M_PI) * 0.2);
                SDL_Color infoCol;
                if(mD.touch) infoCol = {255,0,0,255};
                else         infoCol = {0  ,0,0,255};

                enterBut.getState(mD.pos, butClk, butHov);

                mouseTextX.changeContent(gfx->getRenderer(), "mouse x: " + std::to_string(mD.pos.x),
                                         font3, {0.01,0.01}, false, infoCol);

                mouseTextY.changeContent(gfx->getRenderer(), "mouse y: " + std::to_string(mD.pos.y),
                                         font3, {0.01,0.05}, false, infoCol);

                buttTextHov.changeContent(gfx->getRenderer(), "button click: " + std::to_string(butClk), font3,
                                          {0.01, 0.09}, false, {0,0,0,255});

                buttTextClk.changeContent(gfx->getRenderer(), "button hover: " + std::to_string(butHov), font3,
                                          {0.01, 0.13}, false, {0,0,0,255});

                if(butClk)
                {
                    screen1 = screen3 = false;
                    screen2 = true;
                }

                gfx->eventHndlr();

                if(++i < 10000)
                    i = 0;
            }
        }
        else if(screen2)
        {

            button but1(gfx->getRenderer(), {0.25, 0.05}, {0.4, 0.05}, true);

            button but2(gfx->getRenderer(), {0.75, 0.05}, {0.4, 0.05}, true);

            button but3(gfx->getRenderer(), {0.5, 0.15}, {0.8, 0.05}, true);

            text   butText1(gfx->getRenderer(), "Do ekranu 1", font1, {0.25, 0.05}, true, {0,0,0,255});

            text   butText2(gfx->getRenderer(), "Do ekranu 3", font1, {0.75, 0.05}, true, {0,0,0,255});

            text   butText3(gfx->getRenderer(), "Exit", font1, {0.5, 0.15}, true, {0,0,0,255});

            while(!gfx->propWannaQuit() && screen2)
            {
                gfx->pushRenderStack(butText1.get());
                gfx->pushRenderStack(butText2.get());
                gfx->pushRenderStack(butText3.get());
                gfx->pushRenderStack(but1.get());
                gfx->pushRenderStack(but2.get());
                gfx->pushRenderStack(but3.get());
                gfx->consumeRenderStack();

                mouseData mD = gfx->getTouch();

                bool b1C, b2C, b3C, emptyB;
                b1C = b2C = b3C = mD.touch;

                but1.getState(mD.pos, b1C, emptyB);
                but2.getState(mD.pos, b2C, emptyB);
                but3.getState(mD.pos, b3C, emptyB);

                SDL_Color infoCol;
                if(mD.touch) infoCol = {255,0,0,255};
                else         infoCol = {0  ,0,0,255};

                if(b1C)
                {
                    screen2 = screen3 = false;
                    screen1 = true;
                }
                else if(b2C)
                {
                    screen1 = screen2 = false;
                    screen3 = true;
                }
                else if(b3C)
                {
                    SDL_Event* e = new SDL_Event;
                    e->type = SDL_QUIT;
                    SDL_PushEvent(e);
                }

                gfx->eventHndlr();
            }
        }
        else if(screen3)
        {
            vector2D iPos = {0.5, 0.5};
            vector2D mPos = {0.5, 0.5};

            bool alreadyClicked = false;

            image    mapa(gfx->getRenderer(), "./Data/Image/mapmain.bmp", {0.5, 0.5}, 1., true);

            while(!gfx->propWannaQuit() && screen3)
            {
                gfx->pushRenderStack(mapa.get());
                gfx->consumeRenderStack();

                mouseData mD = gfx->getTouch();



                if(mD.touch)
                {
                    if(!alreadyClicked)
                    {
                        alreadyClicked = true;
                        mPos = mD.pos;
                    }

                    if(GetAsyncKeyState(VK_SHIFT))
                    {
                        mapa.sO.scaleR(1. + (mPos.y - mD.pos.y) * 0.01);
                    }
                    else
                    {
                        iPos.x -= (mD.pos.x - mPos.x) * 0.02;
                        iPos.y -= (mD.pos.y - mPos.y) * 0.02;
                    }

                    mapa.sO.moveG(iPos, true);

                }
                else
                    alreadyClicked = false;

                gfx->eventHndlr();
            }
        }
    }

    delete gfx;
	return 0 & (argc + **args);
}



