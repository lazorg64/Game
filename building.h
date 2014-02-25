#ifndef BUILDING_H
#define BUILDING_H

#include "mesh.h"
class building
{
protected:
    int posx,posy;
    texture_buffer * tex;
    GLuint texids[5];
    float money;
public:

    building(int x,int y);
    virtual void draw() = 0;
    float getMoney();
    void setMoney(float m);
    //~building();
    int getX();
    int getY();

};

#endif // BUILDING_H
