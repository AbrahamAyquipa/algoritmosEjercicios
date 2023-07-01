#pragma once
#include "Figura.h"

class Cuadrado :public Figura {
public:
	Cuadrado() :Figura() {
		y = 20;
	}

	void mostrar(Graphics^ g) {
		g->DrawRectangle(Pens::DarkRed, x, y, ancho, alto);
		g->DrawString(puntos.ToString(), gcnew Font("Arial", 10), Brushes::Brown, x + (ancho / 2 - 5), y + (alto / 2 - 5));
	}
};
