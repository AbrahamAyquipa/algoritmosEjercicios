#pragma once
#include "Forma.h"

class Rectangulo : public Forma {
public:
	Rectangulo(double base, double altura, double lado1, double lado2, double lado3) : Forma(base, altura, lado1, lado2, lado3) {}

	~Rectangulo() {}

	void calcularArea() {
		cout << (base * altura);
	}

	void calcularPerimetro() {
		cout << (base * 2) + (altura * 2);
	}
};
