#include <iostream>

#include "Game.h"
#include "GL/freeglut.h"

Game Conway;

void display()
{
	std::cout << "+++Running Display+++" << std::endl;
	// clear the drawing buffer. dont need depth but anyways
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Conway.DrawGrid();
	
	glutSwapBuffers();
	//glFlush();
	std::cout << "+++Running Display+++" << std::endl;
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
	//gluOrtho2D(1.0 * ratio, 1.0 * ratio, -1.0, 1.0);
	gluLookAt(
		0.0f, 0.0f, 50.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	);
	glMatrixMode(GL_MODELVIEW);
}

void animation()
{
	
	for (int ii = 0; ii < Conway.GetGridX(); ii++)
	{
		for (int jj = 0; jj < Conway.GetGridY(); jj++)
		{
			Conway.ChangeState(ii, jj);
		}
	}

	glutPostRedisplay();
}

void timer(int value)
{

	for (int ii = 0; ii < Conway.GetGridX(); ii++)
	{
		for (int jj = 0; jj < Conway.GetGridY(); jj++)
		{
			Conway.ChangeState(ii, jj);
		}
	}

	glutPostRedisplay();
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnable(GL_DEPTH_TEST); // comment this out and see what happens.

}


int main(int argc, char **argv) {
    
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Conway's Game Of Life");
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(animation);
	//glutTimerFunc(50, timer, 0);
	Conway.GameInit();
	init();
	glutMainLoop();
	

    return 0;
}

