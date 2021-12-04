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

void Face::printGprahicsFaceVertexWireframe(vector<vertex> VertexList,float color[])
{
	glColor3f(color[0], color[1],color[2]);
	vector<vertex>::iterator vertexIterator;
	vertexIterator = VertexList.begin();
	glBegin(GL_LINE_LOOP);
	for (verticesOfFaceIterator = vertices.begin(); verticesOfFaceIterator != vertices.end(); ++verticesOfFaceIterator)
		glVertex3f(vertexIterator[*(verticesOfFaceIterator)-1].getPosX(), vertexIterator[*(verticesOfFaceIterator)-1].getPosY(), vertexIterator[*(verticesOfFaceIterator)-1].getPosZ());

	glEnd();


}

void Face::addVertexToFace(int nVertex)
{
	vertices.push_back(nVertex);
}

void Face::ShowFaceVertices()
{
	for (verticesOfFaceIterator = vertices.begin(); verticesOfFaceIterator != vertices.end(); ++verticesOfFaceIterator)
		cout << "<" << *verticesOfFaceIterator << ">";
	cout << endl;
}
