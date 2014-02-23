#ifndef OFFICE_H
#define OFFICE_H
#include "../building.h"

class Office : public building
{
public:
    Office(int x,int y);
    virtual void draw();
};

#endif // OFFICE_H
