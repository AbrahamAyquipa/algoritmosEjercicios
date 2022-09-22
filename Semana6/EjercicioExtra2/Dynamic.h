#pragma once
#include "Vehiculo.h"

class Dynamic:public Vehiculo
{
public:
	Dynamic(double px, int py);
	~Dynamic();
	//met acceso
	double get_x();

};
//IMPLEMENTACION
Dynamic::Dynamic(double px, int py):Vehiculo(px,py)
{

}

Dynamic::~Dynamic()
{}

double Dynamic::get_x()
{
	return this->x;
}
