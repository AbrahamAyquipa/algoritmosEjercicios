#pragma once
#include "Circulo.h"
#include "Cuadrado.h"
#include "Rombo.h"

class Carrera {
private:
	Cuadrado* cuadrado;
	Circulo* circulo;
	Rombo* rombo;
	int meta, round;
public:
	Carrera() {
		cuadrado = new Cuadrado();
		circulo = new Circulo();
		rombo = new Rombo();
		meta = 800;
		round = 1;
	}

	~Carrera() {
		delete cuadrado;
		delete circulo;
		delete rombo;
	}

	void Reset() {
		round++;
		cuadrado->Reset();
		circulo->Reset();
		rombo->Reset();
	}

	int getRound() { return round; }

	void mover() {
		cuadrado->mover();
		circulo->mover();
		rombo->mover();
	}

	void mostrar(Graphics^ g) {
		g->Clear(Color::White);
		g->DrawString("Round: " + round.ToString(), gcnew Font("Arial", 10), Brushes::Black, 0, 0);
		Rectangle recMeta = Rectangle(meta, 0, 20, g->VisibleClipBounds.Bottom);
		g->FillRectangle(Brushes::Black, recMeta);
		cuadrado->mostrar(g);
		circulo->mostrar(g);
		rombo->mostrar(g);
		if (recMeta.IntersectsWith(cuadrado->getArea())) {
			cuadrado->agregarPunto();
			Reset();
		}
		if (recMeta.IntersectsWith(circulo->getArea())) {
			circulo->agregarPunto();
			Reset();
		}
		if (recMeta.IntersectsWith(rombo->getArea())) {
			rombo->agregarPunto();
			Reset();
		}
	}
};
