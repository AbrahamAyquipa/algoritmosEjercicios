#pragma once
using namespace System::Drawing;

class Figura {
protected:
	//atributos de la clase 
	int x, y, dx, dy;

public:
	Figura(int x, int y);
	~Figura();
	virtual void dibujar(Graphics^ g);
	virtual void borrar(Graphics^ g);
	virtual void mover(Graphics^ g);
};

Figura::Figura(int x, int y) {
	this->x = x;
	this->y = y;
	this->dx = 5;
	this->dy = 5;
}

Figura::~Figura() {};

void Figura::mover(Graphics^ g) {
	borrar(g);
	//establecer limites
	if (x + dx<1 || x + dx>g->VisibleClipBounds.Width) dx = dx * -1;
	if (y + dy<1 || y + dy>g->VisibleClipBounds.Height) dy = dy * -1;
	x += dx;
	y += dy;
	dibujar(g);
}

void Figura::borrar(Graphics^ g) {};

void Figura::dibujar(Graphics^ g) {};
