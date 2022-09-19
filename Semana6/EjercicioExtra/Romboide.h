#pragma once
#include "Forma.h"

class Romboide : public Forma {
public:
	Romboide(double base, double altura);
	~Romboide();

	void calcularAreaRomboide(double base, double altura);
	void calcularPerimetroRomboide(double base, double altura);
};

Romboide::Romboide(double base, double altura) : Forma(base, altura) {}

Romboide::~Romboide() {}

void Romboide::calcularAreaRomboide(double base, double altura) {
	cout << calcularArea(base, altura);
}

void Romboide::calcularPerimetroRomboide(double base, double altura) {
	cout << calcularPerimetro(base, altura);
}
