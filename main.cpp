#include <iostream>

#include "Game.h"
#include "GL/freeglut.h"

Game Conway;

void display()
{
	glMatrixMode(GL_MODELVIEW);
	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	Conway.DrawGrid();
	glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	int width = w;
	int height = h;

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0) h = 1;
	GLfloat ratio = 1.0f * w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 1, 500);
	gluLookAt(
		0.0f, 0.0f, 200.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	);
	glMatrixMode(GL_MODELVIEW);
}

void animation(void)
{
	display();
}

int main(int argc, char **argv) {
    
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutCreateWindow("Conway's Game Of Life");
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(50, 50);
	Conway.GameInit();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(animation);
	glutMainLoop();
	

    return 0;
}

