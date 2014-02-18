#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <building.h>
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
