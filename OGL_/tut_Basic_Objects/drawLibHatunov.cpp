#include "drawLibHatunov.h"
//glTranslatef(x,y,z);  -  ����������� ������
//glRotatef(a,x,y,z);  -  ������� ������
//glScalef(x,y,z);  -  ������ ������
//A * sin(w * i + f) A-���������, f - ������� �����, w(i) - �������
//
//�������� ��������
//glVertex2f(350 * sin(5 * i * M_PI / 180 + 20), 500 * sin(1.5 * i * M_PI / 180 - 3));

//��������� ��������
float  fun(float x) {//D
    float y;

    if (x > 1)
        y = 3 * x - 7;
    else if (x < 1)
        y = 3 * fabs(x + 2) - 7;
    else
        y = 1;

    return y;
}

void drafGraf() {
    glPushMatrix();
    glBegin(GL_LINES);
    //x
    glColor3f(.9, .9, .9);
    glVertex2f(50., .0);
    glVertex2f(-50., .0);
    //y
    glColor3f(.9, .9, .9);
    glVertex2f(.0, 50.);
    glVertex2f(.0, -50.);

    glEnd();

    glScalef(.05, .05, 1);
    glBegin(GL_LINE_STRIP);

    for (float i = -1000; i < 1000; i += 1) {
        glColor3f(0, 1, 0);
        glVertex2f(i, fun(i));
    }
    glEnd();
    glPopMatrix();
}

//������
void dravSkay() {
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    //����� 1
    glColor3f(.9, .9, .9);
    glVertex2f(.0, .0);
    glVertex2f(.0, .22);
    glVertex2f(-.31, .11);
    //����� 2
    glColor3f(.9, .9, .9);
    glVertex2f(-.31, .32);
    glVertex2f(.0, .11);
    glVertex2f(-.31, .11);
    //������-�����
    glColor3f(.9, .9, .9);
    glVertex2f(.99, .11);
    glVertex2f(.78, .0);
    glVertex2f(.78, .22);
    glEnd();

    glBegin(GL_QUADS);
    //������
    glColor3f(1, 1, 1);//71 7 71
    glVertex2f(.0, .0);
    glVertex2f(.78, .0);
    glVertex2f(.78, .22);
    glVertex2f(.0, .22);
    //���� 1
    glColor3f(.3, .3, .3);
    glVertex2f(.62, .16);
    glVertex2f(.62, .05);
    glVertex2f(.73, .05);
    glVertex2f(.73, .16);
    //���� 2
    glColor3f(.3, .3, .3);
    glVertex2f(.57, .16);
    glVertex2f(.57, .05);
    glVertex2f(.46, .05);
    glVertex2f(.46, .16);
    //���� 3 
    glColor3f(.3, .3, .3);
    glVertex2f(.30, .16);
    glVertex2f(.30, .05);
    glVertex2f(.41, .05);
    glVertex2f(.41, .16);
    //���� 4
    glColor3f(.3, .3, .3);
    glVertex2f(.25, .16);
    glVertex2f(.25, .05);
    glVertex2f(.14, .05);
    glVertex2f(.14, .16);
    glEnd();
    glPopMatrix();
}

//���
void DravFon()
{
    glBegin(GL_QUADS);

    glColor3f(.1, .6, .0);
    glVertex2f(1., -.35);
    glVertex2f(-1., -.35);
    glVertex2f(-1., -1.);
    glVertex2f(1., -1.);

    glEnd();
    glBegin(GL_QUADS);

    glColor3f(.1, .1, .69);
    glVertex2f(1., -.35);
    glVertex2f(-1., -.35);
    glVertex2f(-1., -.10);
    glVertex2f(1., -.10);

    glEnd();
    glBegin(GL_QUADS);

    glColor3f(.0, .0, .9);
    glVertex2f(1., -.10);
    glVertex2f(-1., -.10);
    glVertex2f(-1., 1.);
    glColor3f(.9, .9, .9);
    glVertex2f(1., 1.);

    glEnd();
}

//��� �� ������ ���
void DravCat(float R, float G, float B, float x, float y, bool q, float angel) {
    glPushMatrix();
    
    glTranslatef(x + 0.1, y + 0.1, 0);
    glRotatef(angel, 0, 0, 1);
    if(q)
        glRotatef(180, 0, 1, 0);

    glBegin(GL_TRIANGLES);//�������
    glColor3f(R, G, B);
    glVertex2f(-.2, -.3);
    glVertex2f(.4, .0);
    glVertex2f(.55, -.02);
    //����
    glColor3f(1, .3, .0);
    glVertex2f(-.2, -.3);
    glColor3f(.7, .7, .7);
    glVertex2f(.2, -0.3);
    glColor3f(1, .3, .0);
    glVertex2f(0, .2);
    //������
    glColor3f(1, .3, .0);
    glVertex2f(.2, .3);
    glColor3f(1, .3, .0);
    glVertex2f(0, -.1);
    glColor3f(.7, .7, .7);
    glVertex2f(-.2, .3);
    //��� �
    glColor3f(8, .8, .8);
    glVertex2f(-.1, .3);
    glColor3f(1, .2, .0);
    glVertex2f(-.15, .4);
    glVertex2f(-.2, .3);
    //��� �
    glColor3f(8, .8, .8);
    glVertex2f(.1, .3);
    glColor3f(1, .2, .0);
    glVertex2f(.15, .4);
    glVertex2f(.2, .3);
    //���� �
    glColor3f(.3, .6, .3);
    glVertex2f(-.11, .25);
    glVertex2f(-.03, .25);
    glVertex2f(-.07, .19);
    //���� �
    glColor3f(.3, .6, .3);
    glVertex2f(.11, .25);
    glVertex2f(.03, .25);
    glVertex2f(.07, .19);
    //����� �
    glColor3f(.2, .2, .2);
    glVertex2f(.25, -.31);
    glVertex2f(.15, -.31);
    glVertex2f(.2, -.24);
    //����� �
    glColor3f(.2, .2, .2);
    glVertex2f(-.25, -.31);
    glVertex2f(-.15, -.31);
    glVertex2f(-.2, -.24);
    //���
    glColor3f(.9, .2, .1);
    glVertex2f(.0, .16);
    glVertex2f(-.03, .13);
    glVertex2f(.03, .13);
    glEnd();
    glPopMatrix();
}  // ��� �� ������ ���

//��� �� ������ ������
void DravCar(float R, float G, float B) {
    glPushMatrix();
    glBegin(GL_QUADS);
    //������ �
    glColor3f(.61, .63, .61);
    glVertex2f(.68, .04);
    glVertex2f(.76, -.04);
    glVertex2f(.68, -.12);
    glVertex2f(.60, -.04);
    //������ �
    glColor3f(.61, .63, .61);
    glVertex2f(.3, .04);
    glVertex2f(.38, -.04);
    glVertex2f(.3, -.12);
    glVertex2f(.22, -.04);
    //������
    glColor3f(R, G, B);//71 7 71
    glVertex2f(.2, .0);
    glVertex2f(.78, .0);
    glVertex2f(.78, .24);
    glVertex2f(.2, .24);
    //������ ������
    glColor3f(.71, .7, .71);
    glVertex2f(.90, .0);
    glVertex2f(.78, .0);
    glVertex2f(.78, .13);
    glVertex2f(.90, .13);
    //���� ������
    glColor3f(.3, .3, .3);
    glVertex2f(.67, .23);
    glVertex2f(.67, .14);
    glVertex2f(.76, .14);
    glVertex2f(.76, .23);
    glEnd();
    glPopMatrix();
};

//��� �� ������ ���
void DravHome(float y1, float y2, float y3, float y4, float x1, float x2, float x3, float x4, float x, float y)
{
    glPushMatrix();

    glScalef(.8, .8, 1);
    glTranslatef(x + 0.7, y - 0.7, 0);

    glBegin(GL_QUADS);
    //����� ����
    glColor3f(.9, .9, .9);
    glVertex2f(x1, y1);//-42 5
    glColor3f(.5, .5, .5);
    glVertex2f(x2, y2);//-42 0
    glColor3f(.9, .9, .9);
    glVertex2f(x3, y3);//-3 0
    glVertex2f(x4, y4);//-3 5
    glEnd();
    //���
    glScalef(1.3, 1.3, 1.3);
    glTranslatef(-.2, .0, .0);
    glBegin(GL_TRIANGLES);
    // ����� 1
    glColor3f(.9, .9, .9);
    glVertex2f(.0, .0);
    glVertex2f(-.5, .0);
    glVertex2f(.0, -.5);
    // ����� 2
    glColor3f(.5, .5, .5);
    glVertex2f(-.5, -.5);
    glColor3f(.9, .9, .9);
    glVertex2f(-.5, .0);
    glVertex2f(.0, -.5);
    //�����
    glColor3f(.5, .5, .5);
    glVertex2f(-.6, .0);
    glColor3f(.9, .5, .5);
    glVertex2f(-.25, .3);
    glVertex2f(.1, .0);
    glEnd();
    glTranslatef(.0, -.23, .0);
    glBegin(GL_QUADS);
    // ����� ����
    glColor3f(.9, .5, .5);
    glVertex2f(-.1, -.27);
    glVertex2f(-.22, -.27);
    glVertex2f(-.22, .0);
    glVertex2f(-.1, .0);
    // ���� ����
    glColor3f(.8, .8, .4);
    glVertex2f(-.43, -.05);
    glVertex2f(-.43, .1);
    glVertex2f(-.28, .1);
    glVertex2f(-.28, -.05);
    // ���� ����
    glColor3f(1, 1, 1);
    glVertex2f(-.42, -.04);
    glVertex2f(-.42, .09);
    glVertex2f(-.29, .09);
    glVertex2f(-.29, -.04);
    glEnd();
    glPopMatrix();
}

//��������
void DravSW(float R, float G, float B, float R2, float G2, float B2, float x, float y)
{
    glPushMatrix();

    glTranslatef(-1.0, -1.35, 0);
    glTranslatef(x, y, 0);

    glBegin(GL_QUADS);
    //������ �������
    glColor3f(.5, .2, .0);
    glVertex2f(.2, .6);
    glVertex2f(.93, .6);
    glVertex2f(.78, .44);
    glVertex2f(.35, .44);
    //�����
    glColor3f(.5, .2, .0);
    glVertex2f(.55, .97);
    glVertex2f(.55, .6);
    glVertex2f(.59, .6);
    glVertex2f(.59, .97);
    glEnd();
    glBegin(GL_TRIANGLES);
    //���� 1
    glColor3f(R, G, B);
    glVertex2f(.59, .97);
    glVertex2f(.59, .6);
    glVertex2f(.71, .62);
    //���� 2
    glColor3f(R2, G2, B2);
    glVertex2f(.55, .97);
    glVertex2f(.55, .6);
    glVertex2f(.32, .70);
    glEnd();

    glPopMatrix();
}

//����
void DravEll(float R, float G, float B, float x, float y)
{
    glPushMatrix();
    glTranslatef(-1.0, -.58, 0);
    glTranslatef(x, y, 0);

    glBegin(GL_QUADS);

    glColor3f(.5, .2, .0);
    glVertex2f(.45, .5);
    glVertex2f(.45, .25);
    glVertex2f(.55, .25);
    glVertex2f(.55, .5);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(R, G, B);
    glVertex2f(.3, .5);
    glVertex2f(.7, .5);
    glVertex2f(.5, .7);

    glColor3f(R, G, B);
    glVertex2f(.3, .7);
    glVertex2f(.7, .7);
    glVertex2f(.5, .9);

    glColor3f(R, G, B);
    glVertex2f(.3, .9);
    glVertex2f(.7, .9);
    glVertex2f(.5, 1.1);

    glEnd();
    glPopMatrix();
}
