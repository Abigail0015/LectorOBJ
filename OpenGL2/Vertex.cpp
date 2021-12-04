#include "vertex.h"

using namespace std;

	vertex::vertex() {}

	vertex::vertex(float _posX, float _posY, float _posZ,int _ID)
	{
		ID = _ID;
		posX = _posX;
		posY = _posY;
		posZ = _posZ;
	}

	vertex::vertex(float _posX, float _posY, float _posZ)
	{
		ID = 0;
		posX = _posX;
		posY = _posY;
		posZ = _posZ;
	}
	float vertex::getPosX() 
	{
		return posX;
	}

	float vertex::getPosY()
	{
		return posY;
	}

	float vertex::getPosZ()
	{
		return posZ;
	}
	
	void vertex::setPosX(float _posX)
	{
		posX = _posX;
	}

	void vertex::setPosY(float _posY)
	{
		posY = _posY;
	}

	void vertex::setPosZ(float _posZ)
	{
		posZ = _posZ;
	}

	void vertex::incrementX(float incrX)
	{
		posX += incrX;
	}

	void vertex::incrementY(float incrY)
	{
		posY += incrY;
	}

	void vertex::incrementZ(float incrZ)
	{
		posZ += incrZ;
	}


	void vertex::showVertexText()
	{
		cout << "Vertex #" << ID << " - " << " X: " << posX << " Y: " << posY << " Z: " << posZ << "\n" << endl;
	}



