#ifndef CITYHALL_H
#define CITYHALL_H
#include "../building.h"

class CityHall : public building
{
public:
    CityHall(int x,int y);
    virtual void draw();
};

#endif // CITYHALL_H
