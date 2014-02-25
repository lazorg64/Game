#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H
#include "gamemodel.h"
#include <QGLWidget>
#include <iostream>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <QGLShader>
#include <QtGui/QOpenGLShaderProgram>
#include <QMouseEvent>
#include <QImage>
#include <QTime>
#include <QTimer>

using namespace std;

class OpenGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLWidget(QWidget *parent = 0);
    void setModel(gamemodel * mod);
    void setState(std::string * input);
    void setCurrentBuilding(std::string input);
signals:

public slots:


protected:
    bool camUp;
    bool camDown;
    bool camLeft;
    bool camRight;

    float zoom;


    std::string currentBuilding;
    texture_buffer * textures;
    glm::vec3 rot;
    glm::vec3 default_campos;
    glm::vec3 cursor;
    std::string * state;
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
    void setupShaders();
    void setupCamera();
    void loadTextures();



    void setMatrix();

    void draw();
    void drawAxis();
    void drawGrid();
    void drawCursor();


    void moveCam();
    void inter(glm::vec3 input);

    void mousePressEvent(QMouseEvent * pe);
    void mouseReleaseEvent(QMouseEvent * pe);
    void mouseMoveEvent(QMouseEvent * pe);
    void keyPressEvent(QKeyEvent * pe);
    void wheelEvent(QWheelEvent * pe);
};

#endif // OPENGLWIDGET_H
