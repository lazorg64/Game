#include "texture.h"

texture::texture(QImage * input,string name_input)
{
    pix = new QImage(QGLWidget::convertToGLFormat(*input));
    name = name_input;

    glGenTextures(1,id);
    glBindTexture(GL_TEXTURE_2D, id[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pix->width(),pix->height(), 0, GL_RGBA, GL_UNSIGNED_BYTE,pix->bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

}

string texture::getName()
{
    return name;
}

GLuint texture::getTexId()
{
    return id[0];
}
