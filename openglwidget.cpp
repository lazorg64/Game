#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    model = 0;
    rot = glm::vec3(0,0,0);
    cam_offset = glm::vec3(0,0,0);
    cursor = glm::vec3(0,0,0);
    default_campos = glm::vec3(6,6,6);
    this->setMouseTracking(true);
    currentBuilding = "none";

}

void OpenGLWidget::setState(string *input)
{
    state = input;
}
void OpenGLWidget::setModel(gamemodel *mod)
{
    model = mod;
}

void OpenGLWidget::setCurrentBuilding(string input)
{
    currentBuilding = input;
}



void OpenGLWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LESS);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vertex.vert");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/frag.frag");
    m_program->link();
    m_program->bind();



    Proj = glm::perspective(40.0f, 1.0f, 0.1f, 100.0f);
    View = glm::lookAt(default_campos,glm::vec3(0,0,0),glm::vec3(0,0,1));
    ModelMatrix = glm::mat4(1.0f);


    setMatrix();

    srand(125);
    glEnable(GL_TEXTURE_2D);
    textures = new texture_buffer();
    textures->putTexture(new texture(new QImage(":/textures/beton.jpg"),"beton"));
    textures->putTexture(new texture(new QImage(":/textures/crosshair.png"),"cross"));
    textures->putTexture(new texture(new QImage(":/textures/grad.jpg"),"grad"));
    textures->putTexture(new texture(new QImage(":/textures/road.jpg"),"road"));
    textures->putTexture(new texture(new QImage(":/textures/arrow2.png"),"arrow"));
    glBindTexture(GL_TEXTURE_2D, textures->getTexture("beton"));


    model->buildings.push_back(new CityHall(0,0));


    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);


}

void OpenGLWidget::setMatrix()
{
    glm::mat4 MVP = Proj * View * ModelMatrix;

    float *fM = glm::value_ptr(MVP);
    QMatrix4x4 QMVP(fM,4,4);

    int loc = m_program->uniformLocation("qt_ModelViewProjectionMatrix");
    m_program->setUniformValue(loc,QMVP);
}

void OpenGLWidget::drawCursor()
{

    float size = 0.8;
    glBindTexture(GL_TEXTURE_2D, textures->getTexture("arrow"));
    float x,y;
    x =(int)round(cursor.x);
    y =(int)round(cursor.y);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x,y+size,size);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x,y-size,size);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x,y-size,0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x,y+size,0);
    glEnd();

}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    float scale=0.1;
    glScalef(scale,scale,scale);
    glRotatef(30,1,0,1);

    glColor4f(0,0,0,0);
    draw();
}

void OpenGLWidget::resizeGL(int width, int height)
{

    glViewport(0,0,width,height);

}

void OpenGLWidget::draw()
{
    glBindTexture(GL_TEXTURE_2D, textures->getTexture("grad"));
    drawAxis();
    drawGrid();

    foreach (building * element, model->buildings) {

        element->draw();
    }

    float size = 0.5;
    glBindTexture(GL_TEXTURE_2D,textures->getTexture("cross"));
    glColor4f(0,0,0,0);
    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(cursor.x-size,cursor.y+size,0.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(cursor.x-size,cursor.y-size,0.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(cursor.x+size,cursor.y-size,0.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(cursor.x+size,cursor.y+size,0.01f);
    glEnd();

    if(*state=="build")
    drawCursor();

}

void OpenGLWidget::drawAxis()
{
    glBindTexture(GL_TEXTURE_2D,textures->getTexture("grad"));

    glBegin(GL_LINES);
    glVertex3f( 100.0f,  0.0f,  0.1f);
    glVertex3f(-100.0f,  0.0f,  0.1f);
    glVertex3f( 0.0f,  100.0f,  0.1f);
    glVertex3f( 0.0f, -100.0f,  0.1f);
    glVertex3f( 0.0f,  0.0f,  100.0f);
    glVertex3f( 0.0f,  0.0f, -100.0f);
    glEnd();

}

void OpenGLWidget::drawGrid()
{

    glBegin(GL_LINES);
        for(float i=-100;i<100;i+=1)
        {
            glVertex3f( i,  -100,  0.01f);
            glVertex3f( i,  100,  0.01f);
        }
        for(float i=-100;i<100;i+=1)
        {
            glVertex3f( -100,  i,  0.01f);
            glVertex3f(  100,  i,  0.01f);
        }
    glEnd();


    glBindTexture(GL_TEXTURE_2D, textures->getTexture("beton"));
    glBegin(GL_QUADS);
    float size = 0.5;
    for(int i=-10;i<10;i++)
        for(int j=-10;j<10;j++)
        {

            glTexCoord2f(1,1);
            glVertex3f(i+size,j+size,0);
            glTexCoord2f(1,0);
            glVertex3f(i-size,j+size,0);
            glTexCoord2f(0,0);
            glVertex3f(i-size,j-size,0);
            glTexCoord2f(0,1);
            glVertex3f(i+size,j-size,0);


        }
    glEnd();

}



void OpenGLWidget::mousePressEvent(QMouseEvent *pe)
{
    ptrMouse = pe->pos();

    float x=(2.0f *ptrMouse.x())/(float)width() -1.0f;
    float y=1.0f - (2.0f *ptrMouse.y())/(float)height();
    float z = 0;

    glm::vec3 ray_nds = glm::vec3 (x, y, z);

    glm::vec4 ray_clip = glm::vec4 (ray_nds.x,ray_nds.y, -1.0, 1.0);

    glm::vec4 ray_eye = glm::inverse (Proj) * ray_clip;

    ray_eye = glm::vec4 (ray_eye.x,ray_eye.y, -1.0, 0.0);

    glm::vec4 temp = (glm::inverse (View) * ray_eye);
    glm::vec3 ray_wor;
    ray_wor[0] = temp[0];
    ray_wor[1] = temp[1];
    ray_wor[2] = temp[2];

    ray_wor = glm::normalize (ray_wor);


    glm::vec3 norm = glm::vec3(0,0,1);
    glm::vec3 point = glm::vec3(0,0,0);
    glm::vec3 eye = default_campos;

    glm::vec3 eye2 = eye;
    eye2.z=0;
    glm::vec3 offset = glm::normalize(glm::cross(eye,eye2));
    glm::vec3 temp2 = glm::normalize(default_campos - cam_offset);
    temp2.z = 0;

    if(x>=0.9f)
    {
        cam_offset+=offset;
        default_campos+=offset;
    }
    else if(x<=-0.9f)
    {
        cam_offset-=offset;
        default_campos-=offset;
    }

    if(y>=0.9f)
    {
        cam_offset-=temp2;
        default_campos-=temp2;
    }
    else if(y<=-0.9f)
    {
        cam_offset+=temp2;
        default_campos+=temp2;
    }

    float t = glm::dot((point - eye ),norm)/glm::dot(ray_wor,norm);
    glm::vec3 coord;
    coord = eye + t*ray_wor;

    if(pe->button()==Qt::LeftButton)
    {
        if(*(state)=="build")
        {
            if(currentBuilding=="cityhall")
                model->buildings.push_back(new CityHall((int)round(coord.x),(int)round(coord.y)));
            else if(currentBuilding=="smallhouse")
                model->buildings.push_back(new SmallHouse((int)round(coord.x),(int)round(coord.y)));
            else if(currentBuilding=="factory")
                model->buildings.push_back(new Factory((int)round(coord.x),(int)round(coord.y)));
            else if(currentBuilding=="bar")
                model->buildings.push_back(new Bar((int)round(coord.x),(int)round(coord.y)));
            else if(currentBuilding=="hospital")
                model->buildings.push_back(new Hospital((int)round(coord.x),(int)round(coord.y)));
            else if(currentBuilding=="clothing")
                model->buildings.push_back(new Clothing((int)round(coord.x),(int)round(coord.y)));
            else if(currentBuilding=="store")
                model->buildings.push_back(new Store((int)round(coord.x),(int)round(coord.y)));
            else if(currentBuilding=="leisure")
                model->buildings.push_back(new Leisure((int)round(coord.x),(int)round(coord.y)));
            else if(currentBuilding=="police")
                model->buildings.push_back(new Police((int)round(coord.x),(int)round(coord.y)));
            else if(currentBuilding=="firehouse")
                model->buildings.push_back(new Firehouse((int)round(coord.x),(int)round(coord.y)));
            else if(currentBuilding=="office")
                model->buildings.push_back(new Office((int)round(coord.x),(int)round(coord.y)));
            else
            {

            }
        *state = "default";
        }
    }
    else
    model->selectBuildingByPos((int)round(coord.x),(int)round(coord.y));


    View = glm::lookAt(default_campos,cam_offset,glm::vec3(0,0,1));

    setMatrix();
    updateGL();


}


void OpenGLWidget::inter(glm::vec3 input)
{

    foreach (building * element, model->buildings) {
        glm::vec3 norm = glm::vec3(0,0,1);
        glm::vec3 point = glm::vec3(element->getX(),element->getY(),0);


    }
}


void OpenGLWidget::mouseMoveEvent(QMouseEvent* pe)
{
    ptrMouse = pe->pos();

    float x=(2.0f *ptrMouse.x())/(float)width() -1.0f;
    float y=1.0f - (2.0f *ptrMouse.y())/(float)height();
    float z = 0;

    //cout << "move" <<x << " "<< y<<endl;


    glm::vec3 ray_nds = glm::vec3 (x, y, z);

    glm::vec4 ray_clip = glm::vec4 (ray_nds.x,ray_nds.y, -1.0, 1.0);

    glm::vec4 ray_eye = glm::inverse (Proj) * ray_clip;

    ray_eye = glm::vec4 (ray_eye.x,ray_eye.y, -1.0, 0.0);

    glm::vec4 temp = (glm::inverse (View) * ray_eye);
    glm::vec3 ray_wor;
    ray_wor[0] = temp[0];
    ray_wor[1] = temp[1];
    ray_wor[2] = temp[2];

    ray_wor = glm::normalize (ray_wor);


    glm::vec3 norm = glm::vec3(0,0,1);
    glm::vec3 point = glm::vec3(0,0,0);
    glm::vec3 eye = default_campos;

    glm::vec3 eye2 = eye;
    eye2.z=0;
    glm::vec3 offset = glm::cross(eye,eye2);






    float t = glm::dot((point - eye ),norm)/glm::dot(ray_wor,norm);

    glm::vec3 coord;
    coord = eye + t*ray_wor;
    cursor = coord;

    View = glm::lookAt(default_campos,cam_offset,glm::vec3(0,0,1));

    setMatrix();
    updateGL();
}

void OpenGLWidget::mouseReleaseEvent(QMouseEvent *)
{

}


void OpenGLWidget::keyPressEvent(QKeyEvent* pe)
{
    cout << "KEY" <<endl;
    glm::vec3 eye = default_campos;
    glm::vec3 eye2 = eye;
    eye2.z=0;
    glm::vec3 offset = glm::normalize(glm::cross(eye,eye2));
    glm::vec3 temp2 = glm::normalize(default_campos - cam_offset);
    temp2.z = 0;


    switch (pe->key()){
        case Qt::Key_W:
        cam_offset-=temp2;
        default_campos-=temp2;
        break;
        case Qt::Key_S:
        cam_offset+=temp2;
        default_campos+=temp2;
        break;
        case Qt::Key_A:
        cam_offset-=offset;
        default_campos-=offset;
        break;
        case Qt::Key_D:
        cam_offset+=offset;
        default_campos+=offset;
        break;

    }
    View = glm::lookAt(default_campos,cam_offset,glm::vec3(0,0,1));

    setMatrix();
    updateGL();
}


