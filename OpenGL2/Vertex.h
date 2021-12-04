#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
class vertex
{
	public:

		vertex();
		vertex(float _posX, float _posY, float _posZ, int _ID);
		vertex(float _posX, float _posY, float _posZ);
		float getPosX();
		float getPosY();
		float getPosZ();
		void setPosX(float _posX);
		void setPosY(float _posY);
		void setPosZ(float _posZ);
		void incrementY(float incrY);
		void incrementX(float incrX);
		void incrementZ(float incrZ);
		void showVertexText();

	private:
		int ID;
		float posX;
		float posY;
		float posZ;

	
};
#endif
