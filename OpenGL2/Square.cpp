#include "Square.h"

Square::Square() {}

Square::Square(vertex initialVertex)
{
    points[0].setPosX(initialVertex.getPosX());
    points[0].setPosY(initialVertex.getPosY());
    points[0].setPosZ(initialVertex.getPosZ());

    points[1].setPosX(initialVertex.getPosX() + 1);
    points[1].setPosY(initialVertex.getPosY());
    points[1].setPosZ(initialVertex.getPosZ());

    points[2].setPosX(initialVertex.getPosX() + 1);
    points[2].setPosY(initialVertex.getPosY());
    points[2].setPosZ(initialVertex.getPosZ() - 1);

    points[3].setPosX(initialVertex.getPosX());
    points[3].setPosY(initialVertex.getPosY());
    points[3].setPosZ(initialVertex.getPosZ() - 1);
}

void Square::drawSquare()
{
    glBegin(GL_POLYGON);
    glVertex3f(points[0].getPosX(), points[0].getPosY(), points[0].getPosZ());
    glVertex3f(points[1].getPosX(), points[1].getPosY(), points[1].getPosZ());
    glVertex3f(points[2].getPosX(), points[2].getPosY(), points[2].getPosZ());
    glVertex3f(points[3].getPosX(), points[3].getPosY(), points[3].getPosZ());
    glVertex3f(points[0].getPosX(), points[0].getPosY(), points[0].getPosZ());
    glEnd();
}

void Square::drawLineSquare()
{
    glBegin(GL_LINE_STRIP);
    glVertex3f(points[0].getPosX(), points[0].getPosY(), points[0].getPosZ());
    glVertex3f(points[1].getPosX(), points[1].getPosY(), points[1].getPosZ());
    glVertex3f(points[2].getPosX(), points[2].getPosY(), points[2].getPosZ());
    glVertex3f(points[3].getPosX(), points[3].getPosY(), points[3].getPosZ());
    glVertex3f(points[0].getPosX(), points[0].getPosY(), points[0].getPosZ());
    glEnd();
}

void Square::rotateX(float angle)
{
    float angleRad = angle * (3.141592 / 180);
    float cosAngle = cos(angleRad);
    float sinAngle = sin(angleRad);
    for (int cont = 0; cont < 4; cont++)
    {
        points[cont].setPosY((points[cont].getPosY() * cosAngle) + (points[cont].getPosZ() * (-1 * sinAngle)));
        points[cont].setPosZ((points[cont].getPosY() * sinAngle) + (points[cont].getPosZ() * cosAngle));
    }
}

void Square::rotateY(float angle)
{
    float angleRad = angle * (3.141592 / 180);
    float cosAngle = cos(angleRad);
    float sinAngle = sin(angleRad);
    for (int cont = 0; cont < 4; cont++)
    {
        points[cont].setPosX((points[cont].getPosX() * cosAngle) + (points[cont].getPosZ() * sinAngle));
        points[cont].setPosZ((points[cont].getPosX() * (-1 * sinAngle)) + (points[cont].getPosZ() * cosAngle));
    }
}

void Square::setVertexValues(vertex initialVertex)
{
    points[0].setPosX(initialVertex.getPosX());
    points[0].setPosY(initialVertex.getPosY());
    points[0].setPosZ(initialVertex.getPosZ());
                                       
    points[1].setPosX(initialVertex.getPosX() + 1);
    points[1].setPosY(initialVertex.getPosY());
    points[1].setPosZ(initialVertex.getPosZ());
                                       
    points[2].setPosX(initialVertex.getPosX() + 1);
    points[2].setPosY(initialVertex.getPosY());
    points[2].setPosZ(initialVertex.getPosZ() - 1);
                                       
    points[3].setPosX(initialVertex.getPosX());
    points[3].setPosY(initialVertex.getPosY());
    points[3].setPosZ(initialVertex.getPosZ() - 1);
}

void Square::setVertexValuesY(vertex initialVertex)
{
    points[0].setPosX(initialVertex.getPosX());
    points[0].setPosY(initialVertex.getPosY());
    points[0].setPosZ(initialVertex.getPosZ());
                                       
    points[1].setPosX(initialVertex.getPosX() + 1);
    points[1].setPosY(initialVertex.getPosY());
    points[1].setPosZ(initialVertex.getPosZ());
                                       
    points[2].setPosX(initialVertex.getPosX() + 1);
    points[2].setPosY(initialVertex.getPosY() - 1);
    points[2].setPosZ(initialVertex.getPosZ());
                                       
    points[3].setPosX(initialVertex.getPosX());
    points[3].setPosY(initialVertex.getPosY() - 1);
    points[3].setPosZ(initialVertex.getPosZ());
}
