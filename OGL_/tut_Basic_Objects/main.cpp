#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "drawLibHatunov.h"

int apple = 0;
bool Win = false;
float pos_x = 0,
      pos_y = 0,
      angel = 0,
      apple_x = 0.6,
      apple_y = 0.8;
bool isRight = true;


void renderScene(void);//объ€вление функции

void processKeys(unsigned char key, int x, int y)
{
    //Ћогика упровлени€
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
    
    //логика повидени€
    if ((pos_x >= apple_x - 0.2) && (pos_x <= apple_x + 0.2) &&
        (pos_y <= apple_y + 0.2) && (pos_y >= apple_y - 0.2))
    {
        apple++;
        if(apple == 10) Win = true;
        apple_x = 2 * (float)rand() / RAND_MAX - 1;
        apple_y = 2 * (float)rand() / RAND_MAX - 1;
    }

    if (Win)
        exit(0);

    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    srand(13);
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функци€ должна быть первой в renderScene

    Fig Cat;
    Cat.x = pos_x;
    Cat.y = pos_y;
    Cat.angel = angel;
    Cat.color[0] = 9;
    Cat.color[1] = 9;
    Cat.color[2] = 9;
    DravCat(isRight, Cat);

    Fig Car;
    Car.x = apple_x;
    Car.y = apple_y;
    Car.color[0] = 71;
    Car.color[1] = 7;
    Car.color[2] = 71;
    DravCar(Car);

    glutSwapBuffers(); // эта функци€ должна быть последний в renderScene
}