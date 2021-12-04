#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>

#include <GL/glut.h>
#include <math.h>

#include "Vertex.h"

class Square
{
    private:
        vertex points[4];
    public:
        Square();
        Square(vertex initialVertex);
        void drawSquare();
        void drawLineSquare();
        void rotateX(float angle);
        void rotateY(float angle);
        void setVertexValues(vertex initialVertex);
        void setVertexValuesY(vertex initialVertex);


};


