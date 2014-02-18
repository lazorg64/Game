#include "building.h"

building::building(int x,int y,texture_buffer * input)
{
    posx=x;
    posy=y;
    model = new mesh(input);
}

mesh * building::getmodel()
{
    return model;
}


int building::getX()
{
    return posx;
}
int building::getY()
{
    return posy;
}
