#pragma once
using namespace System;
using namespace System::Drawing;

class Figura {
protected:
	int x, y;
	int ancho, alto;
	int dx;
	int puntos;
public:
	Figura() {
		x = 20;
		alto = ancho = 40;
		puntos = 0;
		Random r;
		dx = r.Next(5, 16);
		System::Threading::Thread::Sleep(10);
	}

	int getPuntos() { return puntos; }

	void agregarPunto() { puntos++; }

	void Reset() {
		x = 20;
		Random r;
		dx = r.Next(5, 16);
		System::Threading::Thread::Sleep(10);
	}

	Rectangle getArea() { return Rectangle(x, y, ancho, alto); }

	void mover() { x += dx; }
};
