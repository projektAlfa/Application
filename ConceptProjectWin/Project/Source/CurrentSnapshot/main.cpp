#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <rende.h>
#include <logger.h>
#include <cmath>
#include <string>

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
    //TTF_Font* font3 = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 18);


    while(!gfx->propWannaQuit())
    {
        //Splash Screen
        {
            button enterBut(gfx->getRenderer(), {0.5, 0.8}, {0.5, 0.05}, true,
                            SCREEN_WIDTH * SCREEN_SCALE,
                            SCREEN_HEIGHT * SCREEN_SCALE);

            text   splashTxt(gfx->getRenderer(), "Poli::Map", font1,
                             {0.5, 0.75}, true, {255,200,150,255},
                             SCREEN_WIDTH * SCREEN_SCALE,
                             SCREEN_HEIGHT * SCREEN_SCALE);

            image  splashImg(gfx->getRenderer(), "./Data/Image/logotype.bmp",
                             {0.5, 0.5} , 1.0, true,
                             SCREEN_WIDTH * SCREEN_SCALE,
                             SCREEN_HEIGHT * SCREEN_SCALE);

            for(int i = 0; i < 10000 && !gfx->propWannaQuit(); i++)
            {
                gfx->pushRenderStack(splashImg.get());
                gfx->pushRenderStack(splashTxt.get());
                gfx->pushRenderStack(enterBut.get());

                mouseData mD;

                mD = gfx->getTouch();

                splashImg.sO.moveG({0.5, float(0.5 + 0.02 * sin(i/5000 * M_PI))}, true);
                splashImg.sO.scaleG(1 + sin(i/2500 * M_PI) * 0.1);

                gfx->consumeRenderStack();
                gfx->eventHndlr();
            }
        }
    }

    delete gfx;
	return 0 & (argc + **args);
}



