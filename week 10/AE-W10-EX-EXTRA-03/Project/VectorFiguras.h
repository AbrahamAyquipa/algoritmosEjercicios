#pragma once
#include "Cuadrado.h"
#include "Circulo.h"
#include <vector>

using namespace System::Drawing;
using namespace System;
using namespace std;

class ArregloFiguras {
private:
	vector<Figura*>* arrf;
public:
	ArregloFiguras();
	~ArregloFiguras();
	void mostrar(Graphics^ g);
	void agregarFigura(Graphics^ g, char op);
};

ArregloFiguras::ArregloFiguras() {
	arrf = new vector<Figura*>();
}

ArregloFiguras::~ArregloFiguras() {
	delete arrf;
}

void ArregloFiguras::mostrar(Graphics^ g) {
	//accediendo a los elementos del arreglo
	for (int i = 0; i < arrf->size(); i++) {
		arrf->at(i)->borrar(g);
		arrf->at(i)->mover(g);
		arrf->at(i)->dibujar(g);
	}
}

void ArregloFiguras::agregarFigura(Graphics^ g, char op) {
	Random r;
	Figura* fig; 
	switch (op) {
	//aplicamos polimorfismo
	case 'C':
		fig = new Circulo(r.Next(g->VisibleClipBounds.Right), r.Next(g->VisibleClipBounds.Bottom), r.Next(10, 30));
		break;
	case 'D':
		fig = new Cuadrado(r.Next(g->VisibleClipBounds.Right), r.Next(g->VisibleClipBounds.Bottom), r.Next(10, 30));
		break;
	default:
		break;
	}
	arrf->push_back(fig);
}
