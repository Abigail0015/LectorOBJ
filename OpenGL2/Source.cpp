#include <GL/freeglut.h>
#include "Vertex.h"
#include "Face.h"
#include "Object.h"
#include "File.h"
using namespace std;


File file;


void display(void)
{
	glClearColor(0.1, 0.1, 0.1, 1.0);
	file.Wireframe();
	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("<LECTOR OBJ>");
	file.readFile("p1.obj");

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	
}









