#pragma once
#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include <cmath>

struct Fig {
	float x, y, angel, color[3];
};

void drafGraf();
void dravPlane(Fig Plane);
void DravFon(Fig sky);
void DravCat(bool q, Fig Cat);
void DravCar(Fig car);
void DravHome(Fig home);
void DravSW(Fig sw);
void DravEll(Fig ell);