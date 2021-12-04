#include <vector>
#include "Vertex.h"
#include <GL/glut.h>
#ifndef FACE_H
#define FACE_H
using namespace std;

class Face
{
private:
	int faceNumber;
	vector<int> vertices;
	vector<int>::iterator verticesOfFaceIterator;
	vector<vertex>::iterator VertexListIlterator;

public:

	Face(int _faceNumber);
	void addVertex(int vertexID);
	int getFaceNumber();
	void printGprahicsFaceVertexWireframe(vector<vertex> VertexList, float color[]);
	void addVertexToFace(int nVertex);
	void ShowFaceVertices();
};

#endif