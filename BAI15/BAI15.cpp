// BAI15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "math.h"

#define PI 3.14159265358979323846
#define STEPS 40
#define MAX_STARTS 300

const int Width = 640;
const int Height = 480;

typedef struct star {
	GLint x, y;
	GLint radius;
	GLint velocity;
	GLfloat intensity;
}STAR;

STAR sky[MAX_STARTS];

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//glShadeModel(GL_SMOOTH);
}

void glCirle(GLint x, GLint y, GLint radius) {
	GLfloat twicePi = (GLfloat)2.0f*PI;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(x, y);
	for (int i = 0; i <= STEPS; i++) {
		glVertex2i((GLint)(x + (radius * cos(i*twicePi / STEPS)) + 0.5), (GLint)(y + (radius * sin(i*twicePi / STEPS)) + 0.5));
	}
	glEnd();
}

void skyInit() {
	for (int i = 0; i < MAX_STARTS; i++) {
		sky[i].x = rand() % Width;
		sky[i].y = rand() % Height;
		sky[i].radius = 1 + rand() % 3;
		sky[i].intensity = sky[i].radius / 3.0f;
		sky[i].velocity = sky[i].radius * 2 + rand() % 3;
	}
}

void skyDraw() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < MAX_STARTS; i++) {
		glColor3f(sky[i].intensity, sky[i].intensity, sky[i].intensity);
		glCirle(sky[i].x, sky[i].y, sky[i].radius);
	}
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	skyDraw();
	glPopMatrix();
	glutSwapBuffers();
}

void update() {
	for (int i = 0; i < MAX_STARTS; i++) {
		sky[i].intensity = (1 + rand() % 3) / 3.0f;
		sky[i].x += sky[i].velocity;
		glColor3f(sky[i].intensity, sky[i].intensity, sky[i].intensity);
		if (sky[i].x>Width || sky[i].x<0)
		{
			sky[i].y = rand() % Height;
			sky[i].radius = 1 + rand() % 3;
			sky[i].intensity = sky[i].radius / 3.0f;
			int dimention = rand() % 2;
			if (dimention)
			{
				sky[i].x = 0;
				sky[i].velocity = sky[i].radius * 2 + rand() % 3;
			}
			else
			{
				sky[i].x = Width;
				sky[i].velocity = -(sky[i].radius * 2 + rand() % 3);
			}
		}
	}
	Sleep(50);
	glutPostRedisplay();
}


void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	skyInit();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(update);
	glutMainLoop();
	return 0;
}

