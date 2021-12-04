#include<string>
#include "Object.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Vertex.h"

using namespace std;

class File
{
	private:
		string name;
		vector<vertex> vertexList;
		vector<vertex>::iterator vertexListIterator;
		vector<Object> ObjectsList;
		vector<Object>::iterator objectsListIterator;
		int numberVertices = 0, ammountObjects = 0, numberFaces = 0;
		ifstream newFile;
		string line;
		///
		float initX =0.0, initY = 0.0, initZ = 0.0;
		float tValue;
		vector<vertex> Curve[3];

	public:
		void Wireframe(float color[]);
		void readFile(string objFileName);
		void showText();
		void objectOrigin();
		void traslation(vertex newPosition);
		void scalation(float scaling[]);
		void rotationYangle(float angle);
		float getTValue();
		void setTValue();
		void addTValue(float step);
		float getInitX();
		float getInitY();
		float getInitZ();
		void setCurvePoints(vertex p1, vertex p2, vertex p3, vertex p4, int curve);
		float getPosX(int index, int id);
		float getPosY(int index, int id);
		float getPosZ(int index, int id);

	

};