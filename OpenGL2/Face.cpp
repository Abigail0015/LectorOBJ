#include "Face.h"

Face::Face(int _faceNumber)
{
	faceNumber = _faceNumber;
}

void Face::addVertex(int vertexID)
{
	vertices.push_back(vertexID);
}

int Face::getFaceNumber()
{
	return faceNumber;
}

void Face::printGprahicsFaceVertexWireframe(vector<vertex> VertexList)
{
	glColor3f(0.0, 1.0, 1.0);
	vector<vertex>::iterator itrVERTEX;
	itrVERTEX = VertexList.begin();
	vector<int> verticesOfFace;
	vector<int>::iterator itrVerticesOfFace;
	glBegin(GL_LINE_LOOP);
	for (itrVerticesOfFace = verticesOfFace.begin(); itrVerticesOfFace != verticesOfFace.end(); ++itrVerticesOfFace)
		glVertex3f(itrVERTEX[*(itrVerticesOfFace)-1].getPosX(), itrVERTEX[*(itrVerticesOfFace)-1].getPosY(), itrVERTEX[*(itrVerticesOfFace)-1].getPosZ());
	glEnd();
}

void Face::addVertexToFace(int nVertex)
{
	vertices.push_back(nVertex);
}