#pragma once
#include "Forma.h"

class Triangulo : public Forma {
public:
	Triangulo(double base, double altura, double lado1, double lado2, double lado3) : Forma(base, altura, lado1, lado2, lado3) {}

	~Triangulo() {}

	void calcularArea() {
		cout << (base * altura) / 2;
	}

	void calcularPerimetro() {
		cout << lado1 + lado2 + lado3;
	}
};
