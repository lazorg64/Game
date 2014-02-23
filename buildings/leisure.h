#ifndef LEISURE_H
#define LEISURE_H

#include "../building.h"

class Leisure : public building
{
public:
    Leisure(int x,int y);
    virtual void draw();
};
#endif // LEISURE_H
