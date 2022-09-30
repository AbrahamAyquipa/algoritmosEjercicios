#pragma once
#include "Forma.h"

class Romboide : public Forma {
public:
	Romboide() : Forma(base, altura) {}
	~Romboide() {}
	void calcularPerimetro(double base, double altura) {
		cout << (base * 2) + (altura * 2);
	}

	void calcularArea(double base, double altura) {
		cout << (base * altura);
	}
};
