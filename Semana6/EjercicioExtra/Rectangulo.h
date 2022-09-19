#pragma once
#include "Forma.h"

class Rectangulo: public Forma {
public:
	Rectangulo(double base, double altura);
	~Rectangulo();

	void calcularAreaRectangulo(double base, double altura);
	void calcularPerimetroRectangulo(double base, double altura);
};

Rectangulo::Rectangulo(double base, double altura) : Forma(base, altura) {}

Rectangulo::~Rectangulo() {}

void Rectangulo::calcularAreaRectangulo(double base, double altura) {
	cout << calcularArea(base, altura);
}

void Rectangulo::calcularPerimetroRectangulo(double base, double altura) {
	cout << calcularPerimetro(base, altura);
}
