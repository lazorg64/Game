#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    model = new gamemodel();
    rot = glm::vec3(0,0,0);
    cam_offset = glm::vec3(0,0,0);
    cursor = glm::vec3(0,0,0);
    default_campos = glm::vec3(5,5,5);
    this->setMouseTracking(true);

}

void OpenGLWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glEnable(GL_BLEND);
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



void OpenGLWidget::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    GLuint texid;

    QPixmap pix;

    QString path(":/images/package_games.png");
    pix.load(path);



    texid=bindTexture(pix,GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,texid);


    float scale=0.1;
    glScalef(scale,scale,scale);
    glRotatef(30,1,0,1);


    glColor4f(0,0,0,1);
    draw();

}

void OpenGLWidget::resizeGL(int width, int height)
{

    glViewport(0,0,width,height);

}

void OpenGLWidget::draw()
{

    drawAxis();
    drawGrid();

    foreach (building * element, model->buildings) {

        element->getmodel()->draw(element->getX(),element->getY());
    }


    float size = 0.1;
    glBegin(GL_QUADS);


    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(cursor.x-size,cursor.y+size,0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(cursor.x-size,cursor.y-size,0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(cursor.x+size,cursor.y-size,0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(cursor.x+size,cursor.y+size,0);
    glEnd();





}
void OpenGLWidget::drawBuilding(building * input)
{
    float x,y;
    x=(float)input->getX();
    y=(float)input->getY();
    float size = 0.5;
    glBegin(GL_QUADS);


 glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x,y,0);
    glTexCoord2f(0.0f, 1.0f);

    glVertex3f(x+size,y,0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x+size,y+size,0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x,y+size,0);




    glEnd();
}
void OpenGLWidget::drawAxis()
{
glDisable(GL_TEXTURE_2D);
    glLineWidth(1.0f);

    glBegin(GL_LINES);
    //glColor4f(1.00f, 0.00f, 0.00f, 1.0f);
    glVertex3f( 100.0f,  0.0f,  0.0f);
    glVertex3f(-100.0f,  0.0f,  0.0f);
   // glColor4f(0.00f, 1.00f, 0.00f, 1.0f);
    glVertex3f( 0.0f,  100.0f,  0.0f);
    glVertex3f( 0.0f, -100.0f,  0.0f);
   // glColor4f(0.00f, 0.00f, 1.00f, 1.0f);
    glVertex3f( 0.0f,  0.0f,  100.0f);
    glVertex3f( 0.0f,  0.0f, -100.0f);
    glEnd();
glEnable(GL_TEXTURE_2D);
}

void OpenGLWidget::drawGrid()
{
    glDisable(GL_TEXTURE_2D);
    glBegin(GL_LINES);
        for(float i=-100;i<100;i+=1)
        {
            glVertex3f( i,  -100,  0.0f);
            glVertex3f( i,  100,  0.0f);
        }
        for(float i=-100;i<100;i+=1)
        {
            glVertex3f( -100,  i,  0.0f);
            glVertex3f(  100,  i,  0.0f);
        }
    glEnd();
    glEnable(GL_TEXTURE_2D);
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
    glm::vec3 offset = glm::cross(eye,eye2);


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
        cam_offset-=eye2*0.1f;
        default_campos-=eye2*0.1f;
    }
    else if(y<=-0.9f)
    {
        cam_offset+=eye2*0.1f;
        default_campos+=eye2*0.1f;
    }

    float t = glm::dot((point - eye ),norm)/glm::dot(ray_wor,norm);

/*

    //cursor = coord;





    */
    glm::vec3 coord;
    coord = eye + t*ray_wor;
    if(pe->button()==Qt::RightButton)
    {
        cout << "x = "<<coord.x<<" int = "<<(int)round(coord.x)<<endl;
        cout << "y = "<<coord.y<<" int = "<<(int)round(coord.y)<<endl;
    model->buildings.push_back(new building((int)round(coord.x),(int)round(coord.y),model->tex_buff));
    }
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
    //cam_offset = coord*0.5f;

    /*

    if(x>=0.9f)
        cam_offset.x-=0.1f;
    else if(x<=-0.9f)
        cam_offset.x+=0.1f;

*/




    View = glm::lookAt(default_campos,cam_offset,glm::vec3(0,0,1));

    setMatrix();
    updateGL();
}

void OpenGLWidget::mouseReleaseEvent(QMouseEvent *)
{

}

