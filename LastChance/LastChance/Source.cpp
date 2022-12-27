#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;
float WinWid = 800, WinHei = 430, rY = 0, rX = 0, 
rZ = 0, z1 = 0, z2 = 0, z = 0, x = 0, y = 0;
int f = 0;


void rotY() { //право
	rY += -3;
}
void rotX() { //лево
	rX += 3;
}
void rotZ() { //вниз
	if (f % 2 == 0) {
		y += 5;
		z += 5;
	}
	else {
		z -= 5;
		y -= 5;
	}

	if (y == 125 || y == -125) {
		f++;
	}
}


void key(int key, int x, int y) {
	switch (key)
	{
	case 27: break;
	case 100: rotX(); break;
	case 102: rotY(); break;
	case 103: rotZ(); break;
	}

}

void init() {
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glOrtho(-WinWid / 2, WinWid / 2, -WinHei / 2, WinHei / 2, -200.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
}


void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(rY, 0.0, 1.0, 0);

	glPushMatrix();
	glRotatef(30, 1, 1, 0);
	// glutSolidCube(100);

	glTranslatef(-140, 0, 0);
	glColor3f(0, 0.9, 0);
	glutSolidSphere(50, 50, 50);

	glTranslatef(70, 0, 10);
	glColor3f(0, 0.9, 0);
	glutSolidSphere(50, 50, 50);

	glTranslatef(70, 0, 10);
	glColor3f(0, 0.9, 0);
	glutSolidSphere(50, 50, 50);

	glTranslatef(70, 0, 10);
	glColor3f(0, 0.9, 0);
	glutSolidSphere(50, 50, 50);

	glTranslatef(50, 18, -20);
	glColor3f(0, 0, 0);
	glutSolidSphere(15, 50, 50);

	glTranslatef(-10, 15, 40);
	glColor3f(0, 0, 0);
	glutSolidSphere(15, 50, 50);

	glPopMatrix();



	glPushMatrix();
	GLfloat position[] = { x,y,z,0 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glRotatef(30, 1, 1, 0);
	glTranslatef(x, y, z);
	glColor3f(0, 0, 0);
	glutSolidCube(5);
	glPopMatrix();



	glutSwapBuffers();
}


int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WinWid, WinHei);
	glutInitWindowPosition(400, 150);
	glutCreateWindow("LIGHT");
	glutDisplayFunc(draw);
	glutSpecialFunc(key);
	glutIdleFunc(draw);
	init();
	glutMainLoop();
}