#pragma once
#include "Entidad.h"

class Basura : public Entidad {
private:
	bool activo;
	int color;
	int width;
	int height;
public:
	Basura(int width, int height) : Entidad(x, y, dx, dy, w, h) {
		System::Random numero_aleatorio;

		this->width = width;
		this->height = height;

		this->x = y = 0;
		this->dx = 1;

		this->w = h = 1;

		this->activo = true;

		this->color = 7;
	}

	~Basura() {}

	void mover() {
		if (this->x + this->dx < 0 || this->x + this->w + this->dx > width) this->dx *= -1;
		this->x += this->dx;
	}

	void imprimir() {
		System::Console::ForegroundColor = (ConsoleColor)this->color;
		System::Console::SetCursorPosition(this->x, this->y); cout << "#";
	}

	void setActivo(bool estado) { this->activo = estado; }
	bool getActivo() { return this->activo; }
};
