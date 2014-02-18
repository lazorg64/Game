#include "texture.h"

texture::texture(QImage * input,string name_input)
{
    pix = new QImage(QGLWidget::convertToGLFormat(*input));
    name = name_input;
}

string texture::getName()
{
    return name;
}
