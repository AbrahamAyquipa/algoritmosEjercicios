#pragma once
#include "Forma.h"

class Romboide : public Forma {
public:
	Romboide(double base, double altura, double lado1, double lado2, double lado3) : Forma(base, altura, lado1, lado2, lado3) {}

	~Romboide() {}

	void calcularArea() {
		cout << (base * altura);
	}

	void calcularPerimetro() {
		cout << (base * 2) + (altura * 2);
	}
};
