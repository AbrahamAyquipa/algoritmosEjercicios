#pragma once
#include "Vehiculo.h"

class Leger : public Vehiculo {
public:
	Leger(double px, int py);
	~Leger();
	double get_x();
};

//IMPLEMENTACION
Leger::Leger(double px, int py) :Vehiculo(px, py) {}

Leger::~Leger(){}

double Leger::get_x() { return this->x; }
