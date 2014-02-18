#ifndef MESH_H
#define MESH_H
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <QImage>
#include <QGLWidget>
#include "texture_buffer.h"

class mesh
{
    texture_buffer * tex;
    GLuint texids[5];
public:

    mesh(texture_buffer * input);
    void draw(int x,int y);

};

#endif // MESH_H
