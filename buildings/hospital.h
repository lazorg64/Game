#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "../building.h"

class Hospital : public building
{
public:
    Hospital(int x,int y);
    virtual void draw();
};
#endif // HOSPITAL_H
