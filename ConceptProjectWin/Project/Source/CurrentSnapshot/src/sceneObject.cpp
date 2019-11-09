#include "sceneObject.h"

void sceneObject::moveG(vector2D v, bool c)
{ pos.x = v.x * staticDef::winDim.x - (c == true) * sRect.w * 0.5 * siz.x;
  pos.y = v.y * staticDef::winDim.y - (c == true) * sRect.h * 0.5 * siz.y; }

void sceneObject::moveR(vector2D v) { pos.x += v.x;
                                      pos.y += v.y; }

void sceneObject::scaleG(float s) { siz.x = s;
                                    siz.y = s; }

void sceneObject::scaleR(float s) { siz.x *= s;
                                    siz.y *= s; }

void sceneObject::scaleRC(float s)
{ moveR({pos.x * (1. - s),
         pos.y * (1. - s)});
  siz.x *= s;
  siz.y *= s; }

void sceneObject::cutV(vector2D a, vector2D b) { sRect.x = int(texSiz.x * a.x);
                                                 sRect.y = int(texSiz.y * a.y);
                                                 sRect.w = int(texSiz.x * b.x);
                                                 sRect.h = int(texSiz.y * b.y); }

void sceneObject::cutReset() { sRect.x = 0;
                               sRect.y = 0;
                               sRect.w = texSiz.x;
                               sRect.h = texSiz.y; }

vector2D sceneObject::getPG()
{
    return pos;
}
