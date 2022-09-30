#pragma once
#include <iostream>
using namespace std;

class Forma {
protected:
	double base;
	double altura;
public:
	Forma(double base, double altura) {
		this->base = base;
		this->altura = altura;
	}

	~Forma() {}
	virtual void calcularPerimetro() {}
	virtual void calcularArea() {}
};
