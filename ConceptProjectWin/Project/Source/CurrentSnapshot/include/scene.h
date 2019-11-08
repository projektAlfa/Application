#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <button.h>
#include <image.h>
#include <iostream>

class scene
{
    public:
        scene(int id);
        ~scene();

        void addImage(image* element);
        void pushToRenderStack(std::stack<sceneObject>* stck);

        int getID();

    private:

        int                                ID           = -1;

        std::vector<image*>                imageList;

};

#endif // SCENE_H
