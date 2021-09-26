#include "vertex.h"


	vertex::vertex(int _ID, double _posX, double _posY, double _posZ)
	{
		ID = _ID;
		posX = _posX;
		posY = _posY;
		posZ = _posZ;
	}

	double vertex::getPosX() 
	{
		return posX;
	}

	double vertex::getPosY()
	{
		return posY;
	}

	double vertex::getPosZ()
	{
		return posZ;
	}
	


