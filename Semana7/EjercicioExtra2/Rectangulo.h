#pragma once
#include "Forma.h"

class Rectangulo : public Forma {
public:
	Rectangulo() : Forma(base, altura) {}
	~Rectangulo() {}
	void calcularPerimetro(double base, double altura) {
		cout << (base * 2) + (altura * 2);
	}

	void calcularArea(double base, double altura) {
		cout << (base * altura);
	}
};
