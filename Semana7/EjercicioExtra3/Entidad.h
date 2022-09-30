#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;
using namespace System::Drawing;

// Entidad es la clase base de las clases Nave, Proyectil y Alien.

class Entidad {
protected:
	int x, dx, alto, ancho;
	float y, dy;

public:
	Entidad(int px, float py, int pdx, int palto, int pancho) {
		x = px;
		y = py;
		dx = pdx;
		alto = palto;
		ancho = pancho;
	}
	~Entidad() {}

	virtual void borrar() {}
	virtual void posicionar() {}
	virtual void dibujar() {}

	Rectangle obtenerRectangulo() {
		return Rectangle(x, y, ancho, alto);
	}
};
