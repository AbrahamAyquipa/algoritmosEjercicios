#pragma once

#include "Figura.h"

class Circulo : public Figura {
private:
	int radio;
public:
	Circulo(int x, int y, int radio);
	~Circulo();
	void dibujar(Graphics^ g);
	void mover(Graphics^ g);
	void borrar(Graphics^ g);
};

Circulo::Circulo(int x, int y, int radio) : Figura(x, y) {
	this->radio = radio;
}

Circulo::~Circulo() {}

void Circulo::dibujar(Graphics^ g) {
	g->DrawEllipse(gcnew Pen(Color::Green), x, y, radio, radio);
}

void Circulo::borrar(Graphics^ g) {
	//Para borrar las figuras solo pintamos el lienzo en blanco
	g->DrawEllipse(gcnew Pen(Color::White), x, y, radio, radio);
}

void Circulo::mover(Graphics^ g) {
	Figura::mover(g);
}
