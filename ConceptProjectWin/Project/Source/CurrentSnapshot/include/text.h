#ifndef TEXT_H
#define TEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <coolDataTypes.h>
#include <sceneObject.h>
#include <rende.h>
#include <staticDef.h>

class text
{
    public:
        text(SDL_Renderer* r, std::string content, TTF_Font* ttF,
             vector2D p, bool c, SDL_Color col);
        ~text();
        sceneObject get();

        void changeContent(SDL_Renderer* r, std::string content, TTF_Font* ttF,
                           vector2D p, bool c, SDL_Color col);

    private:
        sceneObject sO;
};

#endif // TEXT_H
