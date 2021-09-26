#include <stdio.h>
#include<string>
#include<iostream>
#include <GL/freeglut.h>
#include <vector>
#include <conio.h>
#include <fstream>
#include <sstream>
using namespace std;


class Vertex
{
private:
	int ID;
	double posX;
	double posY;
	double posZ;

public:

	Vertex(int _ID, double _posX, double _posY, double _posZ)
	{
		posX = _posX;
		posY = _posY;
		posZ = _posZ;
	}

	double getPosX() 
	{
		return posX;
	}

	double getPosY()
	{
		return posY;
	}

	double getPosZ()
	{
		return posZ;
	}

};


class Face
{
private:
	int faceNumber;
	vector<int> vertices;
	vector<int>::iterator verticesIterator;

public:
	


	Face(int _faceNumber)
	{
		faceNumber = _faceNumber;
	}

	void addVertex(int vertexID)
	{
		vertices.push_back(vertexID);
	}

	int getFaceNumber()
	{
		return faceNumber;
	}

	void printGprahicsFaceVertexWireframe(vector<Vertex> VertexList)
	{
		glColor3f(0.0, 1.0, 1.0);
		vector<Vertex>::iterator itrVERTEX;
		itrVERTEX = VertexList.begin();
		vector<int> verticesOfFace;
		vector<int>::iterator itrVerticesOfFace;
		glBegin(GL_LINE_LOOP);
		for (itrVerticesOfFace = verticesOfFace.begin(); itrVerticesOfFace != verticesOfFace.end(); ++itrVerticesOfFace)
			glVertex3f(itrVERTEX[*(itrVerticesOfFace)-1].getPosX(), itrVERTEX[*(itrVerticesOfFace)-1].getPosY(), itrVERTEX[*(itrVerticesOfFace)-1].getPosZ());
		glEnd();
	}

	void addVertexToFace(int nVertex)
	{
		vertices.push_back(nVertex);
	}
};


class Object
{
	public:
		string name;
		vector<int> vertexIDList;
		vector<int>::iterator vertexIDListIterator;
		vector<Face> faceList;
		vector<Face>::iterator faceListIterator;

		Object(string _name)
		{
			name = _name;
		}
		

		void setName(string _name)
		{
			name = _name;
		}

		void addVertex(int newVertex)
		{
			vertexIDList.push_back(newVertex);
		}

		void addFace(Face newFace)
		{
			faceList.push_back(newFace);
		}

		void printGraphicFaceWireframe(vector<Vertex> VertexList)
		{
			vector<Face> FaceObjectList;
			vector<Face>::iterator itrFaceObjectList;
			for (itrFaceObjectList = FaceObjectList.begin(); itrFaceObjectList != FaceObjectList.end(); ++itrFaceObjectList)
				itrFaceObjectList->printGprahicsFaceVertexWireframe(VertexList);
		}

};


class File
{
public:

	string name;
	vector<Vertex> VertexList;
	vector<Object> ObjectsList;

	
	void readFile(string objFileName)
	{
		int numberVertices = 0, ammountObjects = 0, numberFaces = 0;
		Object auxObject("generico");
		float x, y, z;
		ifstream newFile;
		string line;
		newFile.open(objFileName.c_str(), ios::in);
		if (newFile)
		{
			while (getline(newFile, line))
			{
				if (line[0] == 'o')
				{
					line.erase(0, 1);
					if (ammountObjects >= 1)  ObjectsList.push_back(auxObject);
					Object neObj(line);
					auxObject = neObj;
					numberFaces = 0;
					ammountObjects++;
				}
				else if (line[0] == 'v')
				{
					line.erase(0, 1);
					numberVertices++;
					stringstream vertices;
					vertices << line;
					vertices >> x >> y >> z;
					Vertex auxVertex((x), (y), (z), numberVertices);
					auxObject.addVertex(numberVertices);
					VertexList.push_back(auxVertex);
				}
				else if (line[0] == 'f')
				{
					line.erase(0, 1);
					numberFaces++;
					Face auxF(numberFaces);
					int newVertex;
					stringstream vertices(line);
					while (vertices >> newVertex)
					{
						auxF.addVertexToFace(newVertex);
					}
					auxObject.addFace(auxF);
				}
			}
			ObjectsList.push_back(auxObject);
		}
		else
			cout << "Archivo no encontrado" << endl;
		newFile.close();
	}

	


	void Wireframe()
	{
		vector<Object> ObjectsList;
		vector<Object>::iterator itrObjectsList;
		for (itrObjectsList = ObjectsList.begin(); itrObjectsList != ObjectsList.end(); ++(itrObjectsList))
			itrObjectsList->printGraphicFaceWireframe(VertexList);
	}

};

using namespace std;

File file;
int refresh = 10;



void display(void)
{
	glClearColor(0.1, 0.1, 0.1, 1.0);
	file.Wireframe();
	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("<LECTOR OBJ>");
	file.readFile("p1.obj");

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	
}









