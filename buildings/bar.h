#ifndef BAR_H
#define BAR_H
#include "../building.h"

class Bar : public building
{
public:
    Bar(int x,int y);
    virtual void draw();
};

#endif // BAR_H


