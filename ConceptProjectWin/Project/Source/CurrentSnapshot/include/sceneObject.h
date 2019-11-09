#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <staticDef.h>
#include <coolDataTypes.h>
#include <SDL2/SDL.h>

struct sceneObject
{
        void moveG(vector2D v, bool c);
        void moveR(vector2D v);
        vector2D getPG();

        void scaleG(float s);
        void scaleR(float s);
        void scaleRC(float s);
        void scaleG2(vector2D s);
        void scaleR2(vector2D s);

        void cutV(vector2D a, vector2D b);
        void cutReset();

        SDL_Rect        sRect;
        SDL_Texture*    texPtr;
        vector2D        pos;
        vector2D        siz;
        vector2DInt     texSiz;
};

#endif // SCENEOBJECT_H
