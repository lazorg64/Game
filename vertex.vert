attribute vec4 qt_Vertex;
attribute vec4 qt_MultiTexCoord0;

uniform mat4 qt_ModelViewProjectionMatrix;
varying vec4 qt_TexCoord0;



void main(void)
{
    gl_Position = qt_ModelViewProjectionMatrix * qt_Vertex;
    //qt_TexCoord0 = qt_MultiTexCoord0;
    qt_TexCoord0 = gl_MultiTexCoord0;
    //qt_TexCoord0 = vec4(0.5,0.5,0.5,1);
}
