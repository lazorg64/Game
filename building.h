#ifndef BUILDING_H
#define BUILDING_H

#include "mesh.h"

class building
{
    int posx,posy;
    mesh * model;
public:
    mesh * getmodel();
    building(int x,int y,texture_buffer * input);
    int getX();
    int getY();

};

#endif // BUILDING_H
