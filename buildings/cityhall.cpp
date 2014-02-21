#include "cityhall.h"

CityHall::CityHall(int x,int y):building(x,y)
{
    tex = new texture_buffer();
    tex->putTexture(new texture(new QImage(":/textures/brick_green.gif"),"green"));

    glBindTexture(GL_TEXTURE_2D, tex->getTexture("green"));



}

void CityHall::draw()
{
    float x,y;
    x=posx;
    y=posy;
    float size = 0.25f;
    glm::vec3 a(x+size,y+size,0);
    glm::vec3 b(x-size,y+size,0);
    glm::vec3 c(x-size,y-size,0);
    glm::vec3 d(x+size,y-size,0);
    float size2 = 0.5f;
    float height = 1.1f;
    glm::vec3 as(x+size,y+size,height);
    glm::vec3 bs(x-size,y+size,height);
    glm::vec3 cs(x-size,y-size,height);
    glm::vec3 ds(x+size,y-size,height);

    glBindTexture(GL_TEXTURE_2D, tex->getTexture("green"));

    glBegin(GL_QUADS);

    glTexCoord2f(1,1);
    glVertex3f(a.x,a.y,a.z);
    glTexCoord2f(1,0);
    glVertex3f(b.x,b.y,b.z);
    glTexCoord2f(0,0);
    glVertex3f(c.x,c.y,c.z);
    glTexCoord2f(0,1);
    glVertex3f(d.x,d.y,d.z);


    glTexCoord2f(1,1);
    glVertex3f(as.x,as.y,as.z);
    glTexCoord2f(1,0);
    glVertex3f(bs.x,bs.y,bs.z);
    glTexCoord2f(0,0);
    glVertex3f(cs.x,cs.y,cs.z);
    glTexCoord2f(0,1);
    glVertex3f(ds.x,ds.y,ds.z);



    glTexCoord2f(0,0);
    glVertex3f(as.x,as.y,as.z);
    glTexCoord2f(1,0);
    glVertex3f(bs.x,bs.y,bs.z);
    glTexCoord2f(1,1);
    glVertex3f(b.x,b.y,b.z);
    glTexCoord2f(0,1);
    glVertex3f(a.x,a.y,a.z);

    glTexCoord2f(0,0);
    glVertex3f(bs.x,bs.y,bs.z);
    glTexCoord2f(1,0);
    glVertex3f(cs.x,cs.y,cs.z);
    glTexCoord2f(1,1);
    glVertex3f(c.x,c.y,c.z);
    glTexCoord2f(0,1);
    glVertex3f(b.x,b.y,b.z);

    glTexCoord2f(0,0);
    glVertex3f(cs.x,cs.y,cs.z);
    glTexCoord2f(1,0);
    glVertex3f(ds.x,ds.y,ds.z);
    glTexCoord2f(1,1);
    glVertex3f(d.x,d.y,d.z);
    glTexCoord2f(0,1);
    glVertex3f(c.x,c.y,c.z);

    glTexCoord2f(0,0);
    glVertex3f(ds.x,ds.y,ds.z);
    glTexCoord2f(1,0);
    glVertex3f(as.x,as.y,as.z);
    glTexCoord2f(1,1);
    glVertex3f(a.x,a.y,a.z);
    glTexCoord2f(0,1);
    glVertex3f(d.x,d.y,d.z);



    glEnd();
}
