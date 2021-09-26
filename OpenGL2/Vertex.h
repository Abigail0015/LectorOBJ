#ifndef VERTEX_H
#define VERTEX_H
class vertex
{
	public:

		vertex(int _ID, double _posX, double _posY, double _posZ);
		double getPosX();
		double getPosY();
		double getPosZ();

	private:
		int ID;
		double posX;
		double posY;
		double posZ;

	
};
#endif
