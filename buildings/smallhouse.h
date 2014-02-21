#ifndef SMALLHOUSE_H
#define SMALLHOUSE_H
#include "../building.h"


class SmallHouse : public building
{
public:
    SmallHouse(int x,int y);
    virtual void draw();
};

#endif // SMALLHOUSE_H
