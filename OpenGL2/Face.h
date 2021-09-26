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
	vector<int>::iterator verticesIterator;

public:

	Face(int _faceNumber);
	void addVertex(int vertexID);
	int getFaceNumber();
	void printGprahicsFaceVertexWireframe(vector<vertex> VertexList);
	void addVertexToFace(int nVertex);
};

#endif