#include "Object.h"

Object::Object(string _name)
{
	name = _name;
}


void Object::setName(string _name)
{
	name = _name;
}

void Object::addVertex(int newVertex)
{
	vertexIDList.push_back(newVertex);
}

void Object::addFace(Face newFace)
{
	faceList.push_back(newFace);
}

void Object::printGraphicFaceWireframe(vector<vertex> VertexList)
{
	vector<Face> FaceObjectList;
	vector<Face>::iterator itrFaceObjectList;
	for (itrFaceObjectList = FaceObjectList.begin(); itrFaceObjectList != FaceObjectList.end(); ++itrFaceObjectList)
		itrFaceObjectList->printGprahicsFaceVertexWireframe(VertexList);
}