#ifndef OBJECT_H
#define OBJECT_H
#include <GL/glut.h>
#include <vector>
#include <sstream>
#include "Vertex.h"
#include "Face.h"
#include <iostream>
using namespace std;
class Object
{
private:
	string name;
	vector<int> vertexIDList;
	vector<int>::iterator vertexIDListIterator;
	vector<Face> faceList;
	vector<Face>::iterator faceListIterator;
	
public:
	

	Object(string _name);
	void addVertex(int newVertex);
	void addFace(Face newFace);
	void printGraphicFaceWireframe(vector<vertex> VertexList,float color[]);
	void showObjectName();
	void showVertices(vector<vertex> vertex_main_list);
	void setName(string _name);
	void showFacesList();


	
	
};
#endif