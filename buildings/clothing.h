#ifndef CLOTHING_H
#define CLOTHING_H
#include "../building.h"

class Clothing : public building
{
public:
    Clothing(int x,int y);
    virtual void draw();
};
#endif // CLOTHING_H
