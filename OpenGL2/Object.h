#ifndef OBJECT_H
#define OBJECT_H
#include <GL/glut.h>
#include <vector>
#include <sstream>
#include "Vertex.h"
#include "Face.h"

using namespace std;
class Object
{
public:
	string name;
	vector<int> vertexIDList;
	vector<int>::iterator vertexIDListIterator;
	vector<Face> faceList;
	vector<Face>::iterator faceListIterator;

	Object(string _name);
	void addVertex(int newVertex);
	void addFace(Face newFace);
	void printGraphicFaceWireframe(vector<vertex> VertexList);



private:
	
	void setName(string _name);

};
#endif