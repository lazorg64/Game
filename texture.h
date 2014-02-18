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
public:
    QImage * pix;
    texture(QImage * input,string name_input);
    string getName();
};

#endif // TEXTURE_H
