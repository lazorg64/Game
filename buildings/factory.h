#ifndef FACTORY_H
#define FACTORY_H
#include "../building.h"
class Factory : public building
{
public:
    Factory(int x,int y);
    virtual void draw();
};

#endif // FACTORY_H
