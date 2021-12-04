#include <GL/freeglut.h>
#include "Vertex.h"
#include "Face.h"
#include "Object.h"
#include "File.h"
#include "Square.h"

using namespace std;


void Keyboard(unsigned char key, int x, int y);
void init(void);
void Timer(int value);
void display(void);
void CurvePoints();
void Bezier_Route();
void savePosition();

File ball;
File flag;

vertex ballInit(0.0f, 2.0f, 4.0f);
vertex flagInit(0.0f, -2.0f, -5.6f);



float colorBall[] = { 1.0f, 1.0f, 1.0f };
float colorFlag[] = { 1.0f, 0.0f, 0.0f };


float scalationValue[] = { 0.1f, 0.1f, 0.1f };
vertex positionAuxiliar(0.0f, -3.0f, -6.0f);
float step = 0.01f;
int refresh = 1, activated = 0;
float vx = 0.0, vy = -3.0, vz = -6.0, dist = 3.0;
float tright = 0;
vertex curvePoint(0.0, -3.0, -3.0);
Square floorSquares[50][50];
void setFloor();
void floorX();


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(200, 50);
	glutCreateWindow("<LECTOR OBJ>");
    //PELOTA
    ball.readFile("../pelota.obj");
    ball.scalation(scalationValue);
    ball.objectOrigin();
    ball.traslation(ballInit);
    //BANDERA
    flag.readFile("../flag.obj");
    flag.scalation(scalationValue);
    flag.objectOrigin();
    flag.traslation(flagInit);
    //PISO
    setFloor();

    CurvePoints();
    init();

    glutKeyboardFunc(Keyboard);
    glutTimerFunc(0, Timer, 0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
	
}


void Keyboard(unsigned char key, int x, int y) 
{
    switch (key) 
    {
        case 32:
            if (activated == 0) activated = 1;
            else activated = 0;
        break;

        default: break;

    }
}

void init(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3, 3, 1, 30);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void Timer(int value)
{
    if (activated == 1)
    {
        Bezier_Route();
    }
    glutPostRedisplay();
    glutTimerFunc(refresh, Timer, 0);
}

void display(void)
{
    glClearColor(0.0, 0.0, 0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    floorX();

    ball.Wireframe(colorBall);
    flag.Wireframe(colorFlag);

    glutSwapBuffers();
}

void CurvePoints()
{
    vertex p1(ball.getInitX(), ball.getInitY(), ball.getInitZ());
    vertex p2((vx * .3), 0, (vz * .3));
    vertex p3((vx * .8), 0, (vz * .8));
    vertex p4(vx, vy, vz);

    ball.setCurvePoints(p1, p2, p3, p4, 0);
    ball.setTValue();
}


void Bezier_Route()
{
    float incr = 0;
    float t2, t3;
    float incr2, incr3;


    incr = (1 - ball.getTValue());
    t3 = (float)pow(ball.getTValue(), 3);
    t2 = (float)pow(ball.getTValue(), 2);
    incr2 = (float)pow(incr, 2);
    incr3 = (float)pow(incr, 3);
   curvePoint.setPosX((incr3 * ball.getPosX(0, 0)) + (((3 *ball.getTValue()) * incr2) * ball.getPosX(1, 0)) + ((3 * t2) * incr * ball.getPosX(2, 0)) + (t3 * ball.getPosX(3, 0)));
   curvePoint.setPosY((incr3 * ball.getPosY(0, 0)) + (((3 *ball.getTValue()) * incr2) * ball.getPosY(1, 0)) + ((3 * t2) * incr * ball.getPosY(2, 0)) + (t3 * ball.getPosY(3, 0)));
   curvePoint.setPosZ((incr3 * ball.getPosZ(0, 0)) + (((3 *ball.getTValue()) * incr2) * ball.getPosZ(1, 0)) + ((3 * t2) * incr * ball.getPosZ(2, 0)) + (t3 * ball.getPosZ(3, 0)));
    savePosition();
    ball.traslation(curvePoint);
    if (curvePoint.getPosY() >= -6) 
    {
        ball.addTValue(step);

    }
    else 
    {
        return;
    }
   

}

void savePosition()
{
    positionAuxiliar.setPosX(ball.getInitX());
    positionAuxiliar.setPosY(ball.getInitY());
    positionAuxiliar.setPosZ(ball.getInitZ());
}




///SUELO//
void setFloor()
{
    int posX = -20, posY = -4, posZ = -5;
    vertex aux(posX, posY, posZ);
    for (int cont = 0; cont < 50; cont++)
    {
        aux.setPosZ(posZ);
        for (int cont2 = 0; cont2 < 50; cont2++)
        {
            aux.setPosX(posX);
            floorSquares[cont][cont2].setVertexValues(aux);
            posX++;
        }
        posX = -20;
        posZ++;
    }
}

void floorX()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (int cont = 0; cont < 20; cont++)
        for (int cont2 = 0; cont2 < 40; cont2++)
        {
            glColor3f(0.0f, 0.5f, 0.0f);
            floorSquares[cont][cont2].drawSquare();
            glColor3f(0.0f, 1.0f, 0.0f);
            floorSquares[cont][cont2].drawLineSquare();
        }
    glColor3f(0.29f, 0.0f, 0.51f);
    glEnd();
}







