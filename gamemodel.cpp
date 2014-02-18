#include "gamemodel.h"

gamemodel::gamemodel()
{
    tex_buff = new texture_buffer();
    tex_buff->putTexture(new texture(new QImage(":/textures/brick_green.gif"),"green"));
    tex_buff->putTexture(new texture(new QImage(":/textures/brick_purple.gif"),"purple"));
    tex_buff->putTexture(new texture(new QImage(":/textures/brick_white.gif"),"white"));

/*
    buildings.push_back(new building(1,1,tex_buff));
    buildings.push_back(new building(1,2,tex_buff));
    buildings.push_back(new building(2,3,tex_buff));
    buildings.push_back(new building(0,0,tex_buff));
    buildings.push_back(new building(0,-1,tex_buff));
    buildings.push_back(new building(-4,-3,tex_buff));
    buildings.push_back(new building(-3,-4,tex_buff));
    buildings.push_back(new building(-1,-2,tex_buff));

*/
}
