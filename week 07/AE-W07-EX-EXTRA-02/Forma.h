#pragma once
#include <iostream>
using namespace std;

class Forma {
protected:
	double base;
	double altura;
	double lado1;
	double lado2;
	double lado3;
public:
	Forma(double base, double altura, double lado1, double lado2, double lado3) {
		this->base = base;
		this->altura = altura;
		this->lado1 = lado1;
		this->lado2 = lado2;
		this->lado3 = lado3;
	}

	~Forma() {}
	virtual void calcularPerimetro() {}
	virtual void calcularArea() {}
};
