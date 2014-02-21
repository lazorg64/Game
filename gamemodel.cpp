#include "gamemodel.h"

gamemodel::gamemodel()
{
    //tex_buff = new texture_buffer();
   // tex_buff->putTexture(new texture(new QImage(":/textures/brick_green.gif"),"green"));
   // tex_buff->putTexture(new texture(new QImage(":/textures/brick_purple.gif"),"purple"));
    //tex_buff->putTexture(new texture(new QImage(":/textures/brick_white.gif"),"white"));




}


building * gamemodel::selectBuildingByPos(int x, int y)
{
    foreach (building * element, buildings) {
        if(element->getX()==x&&element->getY()==y)
        {
            cout << "Selected!" <<endl;
            return element;
        }
    }
    return 0;
}
