#pragma once
#include "Entidad.h"

class Alien : public Entidad {
private:
	bool activo;
	int color;
	int width;
	int height;
public:
	Alien(int width, int height) : Entidad(x, y, dx, dy, w, h) {
		System::Random numero_aleatorio;

		this->width = width;
		this->height = height;

		this->x = y = 0;

		int aleatio[2] = {1, -1};
		this->dy = dx = aleatio[numero_aleatorio.Next(0, 2)];

		this->w = 4;
		this->h = 3;

		this->activo = true;

		this->color = 4;
	}

	~Alien() {}

	void mover() {
		if (this->x + this->dx < 0 || this->x + this->w + this->dx > width) this->dx *= -1;
		if (this->y + this->dy < 0 || this->y + this->h + this->dy > height) this->dy *= -1;
		this->x += this->dx;
		this->y += this->dy;
	}

	void imprimir() {
		System::Console::ForegroundColor = (ConsoleColor)this->color;
		System::Console::SetCursorPosition(this->x, this->y + 0); cout << "\\__/";
		System::Console::SetCursorPosition(this->x, this->y + 1); cout << "(00)";
		System::Console::SetCursorPosition(this->x, this->y + 2); cout << "//_\\";
	}

	void setActivo(bool estado) { this->activo = estado; }
	bool getActivo() { return this->activo; }
};
