#include<string>
#include "Object.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class File
{
public:

	string name;
	vector<vertex> VertexList;
	vector<Object> ObjectsList;

	void Wireframe();
	void readFile(string objFileName);
	

};