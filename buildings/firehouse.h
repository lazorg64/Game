#ifndef FIREHOUSE_H
#define FIREHOUSE_H

#include "../building.h"

class Firehouse : public building
{
public:
    Firehouse(int x,int y);
    virtual void draw();
};
#endif // FIREHOUSE_H
