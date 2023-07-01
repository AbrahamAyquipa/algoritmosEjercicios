#pragma once
#include "Entidad.h"

class Monigote : public Entidad {
private:
	int cantidadEstrellasAtrapadas;
	int cantidadBasurasAtrapadas;
	int width, height;
	int color;
public:
	Monigote(int width, int height) : Entidad(x, y, dx, dy, w, h) {
		this->cantidadEstrellasAtrapadas = 0;
		this->cantidadBasurasAtrapadas = 0;

		this->width = width;
		this->height = height;

		System::Random numero_random;

		this->x = numero_random.Next(0, this->width - 1);
		this->y = numero_random.Next(0, this->height - 1);

		this->dx = dy = 1;

		this->w = 1;
		this->h = 2;

		this->color = 14;
	}

	~Monigote() {}

	void cambiarDireccion(char tecla) {
		switch (tecla) {
		case 'W':
			this->dx = 0;
			this->dy = -1;
			break;
		case 'S':
			this->dx = 0;
			this->dy = 1;
			break;
		case 'A':
			this->dx = -1;
			this->dy = 0;
			break;
		case 'D':
			this->dx = 1;
			this->dy = 0;
			break;
		}
	}

	void mover() {
		if (this->x + this->dx < 0 || this->x + this->w + this->dx > width) this->dx = 0;
		if (this->y + this->dy < 0 || this->y + this->h + this->dy > height) this->dy = 0;
		this->x += this->dx;
		this->y += this->dy;
	}

	void imprimir() {
		System::Console::ForegroundColor = (ConsoleColor)this->color;
		System::Console::SetCursorPosition(this->x, this->y + 0); cout << char(64);
		System::Console::SetCursorPosition(this->x, this->y + 1); cout << char(197);
	}

	void agregarEstrellasCapturadas() { ++this->cantidadEstrellasAtrapadas; }
	int getCantidadEstrellasAtrapados() { return this->cantidadEstrellasAtrapadas; }

	void agregarBasurasCapturadas() { ++this->cantidadBasurasAtrapadas; }
	int getCantidadBasurasAtrapadas() { return this->cantidadBasurasAtrapadas; }
};
