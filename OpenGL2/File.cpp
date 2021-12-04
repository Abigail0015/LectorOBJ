#include "File.h"

void File::readFile(string objFileName)
{
    int numberVertices = 0, ammountObjects = 0, numberFaces = 0;
    Object auxObject("generico");
    float x, y, z;
    ifstream newFile;
    string line;
    newFile.open(objFileName.c_str(), ios::in);
    if (newFile)
    {
        while (getline(newFile, line))
        {
            if (line[0] == 'o')
            {
                line.erase(0, 1);
                if (ammountObjects >= 1)  ObjectsList.push_back(auxObject);
                Object neObj(line);
                auxObject = neObj;
                numberFaces = 0;
                ammountObjects++;
            }
             else if (line[0] == 'v')
            {
                line.erase(0, 1);
                numberVertices++;
                stringstream vertices;
                vertices << line;
                vertices >> x >> y >> z;
                vertex auxVertex((x), (y), (z), numberVertices);
                auxObject.addVertex(numberVertices);
                vertexList.push_back(auxVertex);
            }
            else if (line[0] == 'f')
            {
                line.erase(0, 1);
                numberFaces++;
                Face auxF(numberFaces);
                int newVertex;
                stringstream vertices(line);
                while (vertices >> newVertex)
                {
                    auxF.addVertexToFace(newVertex);
                }
                auxObject.addFace(auxF);
            }
        }
        ObjectsList.push_back(auxObject);
    }
    else
        cout << "The file could not be opened..." << endl;
    newFile.close();
}


void File::Wireframe(float color[])
{

	
	for (objectsListIterator = ObjectsList.begin(); objectsListIterator != ObjectsList.end(); ++(objectsListIterator))
		objectsListIterator->printGraphicFaceWireframe(vertexList, color);
}

void File::showText()
{
	for (objectsListIterator = ObjectsList.begin(); objectsListIterator != ObjectsList.end(); ++objectsListIterator)
	{
		objectsListIterator->showObjectName();
		objectsListIterator->showVertices(vertexList);
		objectsListIterator->showFacesList();
	}
}



////////////
void File::objectOrigin()
{
    vertex aux(0.0, 0.0, 0.0, 0), aux2(0.0, 0.0, 0.0, 0.0);
    for (vertexListIterator = vertexList.begin(); vertexListIterator != vertexList.end(); ++vertexListIterator)
    {
        if (vertexListIterator->getPosX() < aux.getPosX()) aux.setPosX(vertexListIterator->getPosX());
        if (vertexListIterator->getPosX() > aux2.getPosX()) aux2.setPosX(vertexListIterator->getPosX());
            
        if (vertexListIterator->getPosY() < aux.getPosY()) aux.setPosY(vertexListIterator->getPosY());
        if (vertexListIterator->getPosY() > aux2.getPosY()) aux2.setPosY(vertexListIterator->getPosY());
            
        if (vertexListIterator->getPosZ() < aux.getPosZ()) aux.setPosZ(vertexListIterator->getPosZ());
        if (vertexListIterator->getPosZ() > aux2.getPosZ()) aux2.setPosZ(vertexListIterator->getPosZ());
    }
    initX = ((aux.getPosX() + aux2.getPosX()) / 2);
    initY = ((aux.getPosY() + aux2.getPosY()) / 2);
    initZ = ((aux.getPosZ() + aux2.getPosZ()) / 2);
}

void File::traslation(vertex newPoint)
{
    float antX = 0, antY = 0, antZ = 0;
    antX = (newPoint.getPosX() - initX);
    antY = (newPoint.getPosY() - initY);
    antZ = (newPoint.getPosZ() - initZ);
    for (vertexListIterator = vertexList.begin(); vertexListIterator != vertexList.end(); ++vertexListIterator)
    {
        vertexListIterator->incrementX(antX);
        vertexListIterator->incrementY(antY);
        vertexListIterator->incrementZ(antZ);
    }
    
    initX = newPoint.getPosX();
    initY = newPoint.getPosY();
    initZ = newPoint.getPosZ();
}

void File::scalation(float scaling[])
{
    for (vertexListIterator = vertexList.begin(); vertexListIterator != vertexList.end(); ++vertexListIterator)
    {
        vertexListIterator->setPosX(vertexListIterator->getPosX() * scaling[0]);
        vertexListIterator->setPosY(vertexListIterator->getPosY() * scaling[1]);
        vertexListIterator->setPosZ(vertexListIterator->getPosZ() * scaling[2]);
    }
}


void File::rotationYangle(float angle)
{
    float angleRad = (float) (angle * (3.141592 / 180));
    float cosAngle = cos(angleRad);
    float sinAngle = sin(angleRad);
    for (vertexListIterator = vertexList.begin(); vertexListIterator != vertexList.end(); ++vertexListIterator)
    {
        //SOBRE Y
        vertexListIterator->setPosX((vertexListIterator->getPosX() * cosAngle) + (vertexListIterator->getPosZ() * sinAngle));
        vertexListIterator->setPosZ((vertexListIterator->getPosX() * (-1 * sinAngle)) + (vertexListIterator->getPosZ() * cosAngle));
        //SOBRE X
        //vertexListIterator->setPosY((vertexListIterator->getPosY() * cosAngle) + (vertexListIterator->getPosZ() *(-1 * sinAngle)));
        //vertexListIterator->setPosZ((vertexListIterator->getPosY() * (-1 * sinAngle)) + (vertexListIterator->getPosZ() * cosAngle));
        //sOBREz
        //vertexListIterator->setPosX((vertexListIterator->getPosX() * cosAngle) + (vertexListIterator->getPosY() * (-1*sinAngle)));
        //vertexListIterator->setPosY((vertexListIterator->getPosX() * sinAngle) + (vertexListIterator->getPosY() * cosAngle));



    }
}

float File::getTValue()
{
    return tValue;
}
void File::setTValue()
{
    tValue = 0;
}

void File::addTValue(float step)
{
    tValue += step;
}

float File::getInitX()
{
    return initX;
}

float File::getInitY()
{
    return initY;
}

float File::getInitZ()
{
    return initZ;
}


void File::setCurvePoints(vertex p1, vertex p2, vertex p3, vertex p4, int curve)
{
    Curve[curve].push_back(p1);
    Curve[curve].push_back(p2);
    Curve[curve].push_back(p3);
    Curve[curve].push_back(p4);
}

float File::getPosX(int index, int id)
{
    return Curve[id][index].getPosX();
}

float File::getPosY(int index, int id)
{
    return Curve[id][index].getPosY();
}

float File::getPosZ(int index, int id)
{
    return Curve[id][index].getPosZ();
}
