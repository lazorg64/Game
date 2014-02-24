#ifndef ROAD_H
#define ROAD_H
#include "../building.h"
class Road:public building
{
public:
    Road(int x,int y);
    virtual void draw();
};

#endif // ROAD_H
