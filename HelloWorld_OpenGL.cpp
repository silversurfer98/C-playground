/*
to install in debian based
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
to compile
g++ HelloWorld_OpenGL.cpp -o HelloWorld_OpenGL -lglut -lGLU -lGL
to run
./HelloWorld_OpenGL
*/

#include <GL/glut.h>
void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, 0.0, 0.5);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.0, 0.0, 0.5);
    glEnd();
    glFlush();
}
 
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}