#ifndef BUILDING_H
#define BUILDING_H

#include "mesh.h"

class building
{
protected:
    int posx,posy;
    texture_buffer * tex;
public:

    building(int x,int y);
    virtual void draw() = 0;
    //~building();
    int getX();
    int getY();

};

#endif // BUILDING_H
