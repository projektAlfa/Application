#include "scene.h"

scene::scene(int id)
{
    ID = id;
}

scene::~scene()
{
    //dtor
}

void scene::addImage(image* element)
{
    imageList.push_back(element);
}

void scene::pushToRenderStack(std::stack<sceneObject>* stck)
{
    std::cout << "scene::pushToRenderStack\n";

    for(unsigned int i = 0; i < imageList.size(); i++)
    {
        imageList[i]->pushToRender(1., stck);
    }
}

int scene::getID() {return ID;}
