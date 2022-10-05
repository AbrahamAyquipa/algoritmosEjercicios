#pragma once
#include <iostream>
using namespace std;
using namespace System;

class Entidad {
protected:
	int x, y;
	int dx, dy;
	int w, h;
public:
	Entidad(int x, int y, int dx, int dy, int w, int h) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->w = w;
		this->h = h;
	}

	~Entidad() {}

	void borrar() {
		for (int i = this->x; i < this->x + this->w; ++i) {
			for (int j = this->y; j < this->y + this->h; ++j) {
				System::Console::SetCursorPosition(i, j);
				cout << ' ';
			}
		}
	}

	virtual void mover() {}
	virtual void imprimir() {}

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	int getW() { return this->w; }
	int getH() { return this->h; }

	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(this->x, this->y, this->w, this->h);
	}
};
