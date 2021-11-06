#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "drawLibHatunov.h"

void renderScene(void);//обевление функции

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(605, 200);
    glutInitWindowSize(600, 600);
    glutCreateWindow("OpenGL Start Applicatio");
    glutDisplayFunc(renderScene);
    glutMainLoop();
    return 0;
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функция должна быть первой в renderScene
    
    /*
    DravFon();    
    
    glScalef(.75, .75, .75);//убрать
    glTranslatef(-.25, -.25, 0);

    glPushMatrix();

    glPushMatrix();

    glTranslatef(.0, -.62, .0);
    DravSW(.9, .9, .9, .5, .9, .9);

    glPopMatrix();

    DravHome(.5, .0, .0, .5, -.42, -.42 , -.3, -.3);

    glPushMatrix();

    glTranslatef(.0, -.52, .0);
    glScalef(0.9, 0.9, 0);
    DravCar(.71, .7, .71);

    glPopMatrix();

    glTranslatef(.62, -.77, .0);
    glScalef(.65, .65, .65);
    DravCat(.9, .0, .0);
   
    glTranslatef(.27, -.15, .0);
    glScalef(.65, .65, .65);
    DravCat(1, .3, .0);

    glPopMatrix();

    glTranslatef(-.52, -1.05, .0);
    glScalef(.9, .9, 0);
    DravEll(.1, .9, .2);
    
    glTranslatef(.22, 1.85, .0);
    dravSkay();
    */

    //for (int i = 0; i < 360; i += 30) DravCat(1, .3, .0, 1.75 * cos(i * M_PI / 180), 1.75 * sin(i * M_PI / 180));

    drafGraf();
    
    glutSwapBuffers(); // эта функция должна быть последний в renderScene
}