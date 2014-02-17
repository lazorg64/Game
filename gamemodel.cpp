#include "gamemodel.h"

gamemodel::gamemodel()
{
    buildings.push_back(new building(1,1));
    buildings.push_back(new building(1,2));
    buildings.push_back(new building(2,3));
    buildings.push_back(new building(0,0));
    buildings.push_back(new building(0,-1));
    buildings.push_back(new building(-4,-3));
    buildings.push_back(new building(-3,-4));
    buildings.push_back(new building(-1,-2));


}
