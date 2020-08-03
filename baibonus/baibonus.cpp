#include "stdafx.h"
#include<math.h>
#include "Dependencies/glew/glew.h"
#include "Dependencies/freeglut/freeglut.h"


const int screenWidth = 1000;
const int screenHeight = 600;
const float PI = 3.1415;

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);

}



void glSpiral(int x, int y, int radius) {

	glPointSize(5);
	glBegin(GL_POINTS);
	float number_segment = 1024.0;


	for (int i = 1; i <= 1024; i += 16)
	{


		float theta = (2 * i * PI) / number_segment;
		float X = (x - (radius / number_segment) * i * (cos(theta)));
		float Y = (y - (radius / number_segment) * i * (sin(theta)));

		glVertex2f(X, Y);
		glColor3f(1.0f,1.0f,1.0f);
		//glColor3f(float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)));
		X = (x - (radius / number_segment) * i * (cos(theta + PI / 4)));
		Y = (y - (radius / number_segment) * i * (sin(theta + PI / 4)));

		glVertex2f(X, Y);
		glColor3f(float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)));

		X = (x + (radius / number_segment) * i * (cos(theta)));
		Y = (y + (radius / number_segment) * i * (sin(theta)));

		glVertex2f(X, Y);
		glColor3f(float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)));
		X = (x + (radius / number_segment) * i * (cos(theta + PI / 4)));
		Y = (y + (radius / number_segment) * i * (sin(theta + PI / 4)));

		glVertex2f(X, Y);
		glColor3f(float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)));
		X = (x - (radius / number_segment) * i * (sin(theta)));
		Y = (y + (radius / number_segment) * i * (cos(theta)));

		glVertex2f(X, Y);
		glColor3f(float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)));
		X = (x - (radius / number_segment) * i * (sin(theta + PI / 4)));
		Y = (y + (radius / number_segment) * i * (cos(theta + PI / 4)));

		glVertex2f(X, Y);
		glColor3f(float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)));
		X = (x + (radius / number_segment) * i * (sin(theta + PI / 4)));
		Y = (y - (radius / number_segment) * i * (cos(theta + PI / 4)));

		glVertex2f(X, Y);
		glColor3f(0.1f,0.1f,0.1f);
		//glColor3f(float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)));
		X = (x + (radius / number_segment) * i * (sin(theta)));
		Y = (y - (radius / number_segment) * i * (cos(theta)));

		glVertex2f(X, Y);
		glColor3f(float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)), float(rand()) / float((RAND_MAX)));


	}

	glEnd();

}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 30; i++)
	{

	}
	glSpiral(screenWidth / 2, screenHeight / 2, 300);


	glFlush();
}
void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)w, 0.0, h * 1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("points");
	init();
	glutDisplayFunc(Display);
	glutReshapeFunc(reshape);
	glutIdleFunc(Display); // chay nhap nhay 
	glutMainLoop();
	return 0;
}