#pragma once
#include "Figura.h"

class Circulo : public Figura {
public:
	Circulo() : Figura() {
		y = 120;
	}

	void mostrar(Graphics^ g) {
		g->DrawEllipse(Pens::Blue, x, y, ancho, alto);
		g->DrawString(puntos.ToString(), gcnew Font("Arial", 10), Brushes::Black, x + 10, y + 10);
	}
};
