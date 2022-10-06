#pragma once
#include "Entidad.h"

class Meteotoro : public Entidad {
private:
	bool activo;
	int color;
	int width;
	int height;
public:
	Meteotoro(int width, int height) : Entidad(x, y, dx, dy, w, h) {
		this->width = width;
		this->height = height;

		this->x = y = 0;
		this->dy = 1;

		this->w = 4;
		this->h = 1;

		this->activo = true;

		this->color = 1;
	}

	~Meteotoro() {}

	void mover() {
		//rebotar vaias veces
		if (this->y + this->dy < 0 || this->y + this->h + this->dy > height) { 
			this->dy *= -1;
			this->color++;
			if (color == 15) color = 1;
		}
		//if (this->y + this->dy < 0 || this->y + this->h + this->dy > height) this->dy += -1; rebotar una sola vez
		this->y += this->dy;
	}

	void imprimir() {
		System::Console::ForegroundColor = (ConsoleColor)this->color;
		System::Console::SetCursorPosition(this->x, this->y); cout << "#__#";
	}

	void setActivo(bool estado) { this->activo = estado; }
	bool getActivo() { return this->activo; }
};
