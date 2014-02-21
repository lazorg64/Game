#include "smallhouse.h"

SmallHouse::SmallHouse(int x,int y):building(x,y)
{
    tex = new texture_buffer();
    tex->putTexture(new texture(new QImage(":/textures/brick_purple.gif"),"purple"));
}

void SmallHouse::draw()
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

    QImage *img;
    img = tex->getTexture("purple");

    if(img->isNull())
        cout << "Null"<<endl;
GLuint texids[2];
    glGenTextures(2,texids);

    glBindTexture(GL_TEXTURE_2D, texids[0]);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->width(),img->height(), 0, GL_RGBA, GL_UNSIGNED_BYTE,img->bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

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
