#pragma once
#include "Figura.h"

class Cuadrado : public Figura {
private:
	int lado;
public:
	Cuadrado(int x, int y, int lado);
	~Cuadrado();
	void dibujar(Graphics^ g);
	void mover(Graphics^ g);
	void borrar(Graphics^ g);

};

Cuadrado::Cuadrado(int x, int y, int lado) : Figura(x, y) {
	this->lado = lado;
}

Cuadrado::~Cuadrado() {}

void Cuadrado::dibujar(Graphics^ g) {
	Pen^ lapicero = gcnew Pen(Color::Red);
	g->DrawRectangle(lapicero, x, y, lado, lado);
}

void Cuadrado::borrar(Graphics^ g) {
	Pen^ lapicero = gcnew Pen(Color::White);
	g->DrawRectangle(lapicero, x, y, lado, lado);
}

void Cuadrado::mover(Graphics^ g) {
	Figura::mover(g);
}
