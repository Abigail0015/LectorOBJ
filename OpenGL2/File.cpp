#include "File.h"

void File::readFile(string objFileName)
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
				vertex auxVertex((x), (y), (z), numberVertices);
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




void File::Wireframe()
{
	vector<Object> ObjectsList;
	vector<Object>::iterator itrObjectsList;
	for (itrObjectsList = ObjectsList.begin(); itrObjectsList != ObjectsList.end(); ++(itrObjectsList))
		itrObjectsList->printGraphicFaceWireframe(VertexList);
}