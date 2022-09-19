#pragma once
#include <iostream>
using namespace std;

class Forma {
protected:
	double base;
	double altura;
public:
	Forma(double base, double altura);
	~Forma();

	double calcularPerimetro(double base, double altura);
	double calcularArea(double base, double altura);
};

Forma::Forma(double base, double altura) {
	this->base = base;
	this->altura = altura;
}

Forma::~Forma() {}

double Forma::calcularPerimetro(double base, double altura) {
	return ((2 * base) + (2 * altura));
}

double Forma::calcularArea(double base, double altura) {
	return base * altura;
}
