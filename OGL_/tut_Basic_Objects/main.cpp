#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "drawLibHatunov.h"

float pos_x = 0, pos_y = 0, angel = 0;
bool isRight = true;
bool isGetFlower[3] = {false, false, false};

void renderScene(void);//���������� �������

void processKeys(unsigned char key, int x, int y)
{
    //������ ����������
    if (key == 100)
    {
        pos_x = pos_x + 0.1;
        isRight = true;
    }
    if (key == 97)
    {
        pos_x = pos_x - 0.1;
        isRight = false;
    }
    if (key == 113)
    {
        angel += 5;
    }
    if (key == 101)
    {
        angel -= 5;
    }
    if (key == 119)
    {
        pos_y = pos_y + 0.1;
    }
    if (key == 115)
    {
        pos_y = pos_y - 0.1;
    }
    
    //������ ���������
    if ((pos_x >= 0.6) && (pos_x <= 1.1) &&
        (pos_y <= -0.5) && (pos_y >= -0.8))
    {
        isGetFlower[0] = true;
    }
    if ((pos_x <= -0.8) && (pos_x >= -1.2) &&
        (pos_y >= 0.7) && (pos_y <= 1.0))
    {
        isGetFlower[1] = true;
    }
    if ((pos_x >= 0.6) && (pos_x <= 1.2) &&
        (pos_y >= 0.7) && (pos_y <= 1.2))
    {
        isGetFlower[2] = true;
    }
    
    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(605, 200);
    glutInitWindowSize(600, 600);
    glutCreateWindow("OpenGL Start Applicatio");
    glutDisplayFunc(renderScene);

    glutKeyboardFunc(processKeys);

    glutMainLoop();
    return 0;
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ��� ������� ������ ���� ������ � renderScene
    
    DravCat(9, 9, 9, pos_x, pos_y, isRight, angel);

    if (!isGetFlower[0])
        DravCar(1, 1, 1, 0.6,-0.8);

    if (!isGetFlower[1])
        DravCar(1, 1, 1, -1.1, 0.8);

    if (!isGetFlower[2])
        DravCar(1, 1, 1, 0.6, 0.8);

    if (isGetFlower[0] && isGetFlower[1] && isGetFlower[2])
            dravSkay();
    //drafGraf();

    glutSwapBuffers(); // ��� ������� ������ ���� ��������� � renderScene
}