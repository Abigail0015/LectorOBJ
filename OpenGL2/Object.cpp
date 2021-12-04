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

void Object::printGraphicFaceWireframe(vector<vertex> VertexList, float color[])
{
	
	
	for (faceListIterator = faceList.begin(); faceListIterator != faceList.end(); ++faceListIterator)
	{

		faceListIterator->printGprahicsFaceVertexWireframe(VertexList, color);
	}
}

void Object::showObjectName()
{
	cout << "\n\nObject: " << name << endl;
}

void Object::showVertices(vector<vertex> vertex_main_list)
{
	vector<vertex>::iterator itr_vertex;
	itr_vertex = vertex_main_list.begin();
	for (vertexIDListIterator = vertexIDList.begin(); vertexIDListIterator != vertexIDList.end(); ++vertexIDListIterator)
		itr_vertex[(*vertexIDListIterator) - 1].showVertexText();
}

void Object::showFacesList()
{
	for (faceListIterator = faceList.begin(); faceListIterator != faceList.end(); ++faceListIterator)
	{
		cout << "Face: " << faceListIterator->getFaceNumber() << endl;
		faceListIterator->ShowFaceVertices();
	}
}