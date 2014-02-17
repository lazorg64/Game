#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H
#include "gamemodel.h"
#include <QGLWidget>
#include <iostream>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <QGLShader>
#include <QtGui/QOpenGLShaderProgram>
#include <QMouseEvent>
#include <QImage>

using namespace std;

class OpenGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLWidget(QWidget *parent = 0);

signals:

public slots:


protected:
    glm::vec3 rot;
    glm::vec3 default_campos;
    glm::vec3 cursor;

    glm::vec3 cam_offset;
    QPoint ptrMouse;
    glm::mat4 Proj;
    glm::mat4 View;
    glm::mat4 ModelMatrix;
    QOpenGLShaderProgram *m_program;
    gamemodel * model;
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void setMatrix();
    void drawBuilding(building * input);
    void draw();
    void drawAxis();
    void drawGrid();

    void inter(glm::vec3 input);

    void mousePressEvent(QMouseEvent* pe);
    void mouseReleaseEvent(QMouseEvent* pe);
    void mouseMoveEvent(QMouseEvent* pe);
};

#endif // OPENGLWIDGET_H
