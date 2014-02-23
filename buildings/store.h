#ifndef STORE_H
#define STORE_H

#include "../building.h"

class Store : public building
{
public:
    Store(int x,int y);
    virtual void draw();
};
#endif // STORE_H
