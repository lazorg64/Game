#include "road.h"

Road::Road(int x,int y):building(x,y)
{
    tex = new texture_buffer();
    tex->putTexture(new texture(new QImage(":/textures/road.jpg"),"roof"));

}

void Road::draw()
{
    float x,y;
    x=posx;
    y=posy;
    float size = 0.53f;
    glm::vec3 a(x+size,y+size,0);
    glm::vec3 b(x-size,y+size,0);
    glm::vec3 c(x-size,y-size,0);
    glm::vec3 d(x+size,y-size,0);
    float height = 0.0002f;
    glm::vec3 as(x+size,y+size,height);
    glm::vec3 bs(x-size,y+size,height);
    glm::vec3 cs(x-size,y-size,height);
    glm::vec3 ds(x+size,y-size,height);

glBindTexture(GL_TEXTURE_2D,tex->getTexture("roof"));
    glBegin(GL_QUADS);



    glTexCoord2f(0,1);
    glVertex3f(as.x,as.y,as.z);
    glTexCoord2f(0,0);
    glVertex3f(bs.x,bs.y,bs.z);
    glTexCoord2f(1,0);
    glVertex3f(cs.x,cs.y,cs.z);
    glTexCoord2f(1,1);
    glVertex3f(ds.x,ds.y,ds.z);
    glEnd();



    glEnd();
}
