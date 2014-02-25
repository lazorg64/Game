#include "building.h"

building::building(int x,int y)
{
    money =0;
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
float building::getMoney()
{
    return money;
}
void building::setMoney(float m)
{
    money=m;
}
