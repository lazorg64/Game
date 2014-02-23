#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <buildings/cityhall.h>
#include <buildings/smallhouse.h>
#include <buildings/factory.h>
#include <buildings/bar.h>
#include <buildings/hospital.h>
#include <buildings/clothing.h>
#include <buildings/firehouse.h>
#include <buildings/leisure.h>
#include <buildings/office.h>
#include <buildings/police.h>
#include <buildings/store.h>
#include <vector>

using namespace std;

class gamemodel
{

public:

    vector<building*> buildings;
    building * selectBuildingByPos(int x,int y);
    gamemodel();
};

#endif // GAMEMODEL_H
