#ifndef POLICE_H
#define POLICE_H
#include "../building.h"

class Police : public building
{
public:
    Police(int x,int y);
    virtual void draw();
};
#endif // POLICE_H
