#include <iostream>

#include "game.h"
#include "GL/freeglut.h"

void display();
void reshape(int w, int h);
game Conway;

int main(int argc, char **argv) {
    
	

	glutInit(&argc, argv);
	//glutInitDisplayMode();
	glutCreateWindow("Conway's Game Of Life");
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	

    return 0;
}

void display()
{
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
	gluPerspective(45, ratio, 1, 300);
	glMatrixMode(GL_MODELVIEW);
}