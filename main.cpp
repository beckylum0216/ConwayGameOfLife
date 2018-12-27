#include <iostream>

#include "Game.h"
#include "GL/freeglut.h"

int width;
int height;
int pixelX;
int pixelY;

Game Conway;

void display()
{
	//std::cout << "+++Running Display+++" << std::endl;
	// clear the drawing buffer. dont need depth but anyways
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Conway.DrawGrid(width, height);
	
	glutSwapBuffers();
	//glFlush();
	//std::cout << "+++Running Display+++" << std::endl;
}

void reshape(int w, int h)
{
	width = w;
	height = h;

	glViewport(0, 0, w, h);
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0) h = 1;
	GLfloat ratio = 1.0f * w / h;
	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	
	//gluPerspective(45, ratio, 1, 500);
	gluOrtho2D(0.0, (1.0/width)*pixelX, 0.0, (1.0/height)*pixelY);
	//gluLookAt(0.0f, 0.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	

}

void animation()
{
	Conway.NewFrame();
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

	pixelX = Conway.GetGridX();
	pixelY = Conway.GetGridY();


}


int main(int argc, char **argv) {
    
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Conway's Game Of Life");
	glutInitWindowSize(width, height);
	glutInitWindowPosition(50, 50);
	//init();
	//Conway.GameInit();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(animation);
	//glutTimerFunc(50, timer, 0);
	Conway.GameInit();
	init();
	glutMainLoop();
	

    return 0;
}

