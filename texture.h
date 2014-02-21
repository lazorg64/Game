#ifndef TEXTURE_H
#define TEXTURE_H

#include <QImage>
#include <string>
#include <vector>
#include <iostream>
#include <QGLWidget>
using namespace std;

class texture
{
    string name;
    GLuint id[1];
public:
    QImage * pix;
    texture(QImage * input,string name_input);
    string getName();
    GLuint getTexId();
};

#endif // TEXTURE_H
