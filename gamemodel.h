#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <buildings/cityhall.h>
#include <buildings/smallhouse.h>
#include <vector>

using namespace std;

class gamemodel
{

public:
    texture_buffer * tex_buff;
    vector<building*> buildings;

    gamemodel();
};

#endif // GAMEMODEL_H
