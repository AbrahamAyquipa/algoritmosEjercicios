#pragma once
#include "Entidad.h"

class Estrella : public Entidad {
private:
	bool activo;
	int color;
public:
	Estrella(int width, int height) : Entidad(x, y, dx, dy, w, h) {
		this->x = y = 0;

		this->w = h = 1;

		this->activo = true;

		this->color = 12;
	}

	~Estrella() {}

	void imprimir() {
		System::Console::ForegroundColor = (ConsoleColor)this->color;
		System::Console::SetCursorPosition(this->x, this->y); cout << "*";
	}

	void setActivo(bool estado) { this->activo = estado; }
	bool getActivo() { return this->activo; }
};
