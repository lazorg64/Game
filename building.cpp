#include "building.h"

building::building(int x,int y)
{
    posx=x;
    posy=y;
}

int building::getX()
{
    return posx;
}
int building::getY()
{
    return posy;
}
