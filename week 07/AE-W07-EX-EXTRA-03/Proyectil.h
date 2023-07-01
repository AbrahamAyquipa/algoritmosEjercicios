#pragma once
#include "Entidad.h"

//Proyectil es una clase derivada de la clase Entidad.


class Proyectil : public Entidad {
private:
	bool visible;
	int marca;

public:
	Proyectil(int px, float py, int pdx, int palto, int pancho) : Entidad(px, py, pdx, palto, pancho) {
		dy = 0.1 + (float(rand() % 10001 + 10000) / RAND_MAX);
		visible = true;
		marca = 0;
	}
	~Proyectil() {}

	int get_marca() {
		return marca;
	}

	void set_marca(int m) {
		marca = m;
	}

	float get_y() {
		return y;
	}

	int get_x() {
		return x;
	}

	bool get_visible() {
		return visible;
	}

	void set_visible(bool v) {
		visible = v;
	}

	void borrar() {
		Console::SetCursorPosition(x, int(y)); cout << "      ";
		Console::SetCursorPosition(x, int(y) + 1); cout << "      ";
		Console::SetCursorPosition(x, int(y) + 2); cout << "      ";
		Console::SetCursorPosition(x, int(y) + 3); cout << "      ";
		Console::SetCursorPosition(x, int(y) + 4); cout << "      ";
		Console::SetCursorPosition(x, int(y) + 5); cout << "      ";
	}

	void posicionar() {
		if (y < Console::WindowTop + 1 || y + alto > Console::WindowHeight) {
			dy *= -1;
		}
		y += dy;
	}

	void dibujar_1() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, int(y)); cout << "  /" << char(92) << "  ";
		Console::SetCursorPosition(x, int(y) + 1); cout << " /  " << char(92) << " ";
		Console::SetCursorPosition(x, int(y) + 2); cout << " |  | ";
		Console::SetCursorPosition(x, int(y) + 3); cout << " |  | ";
		Console::SetCursorPosition(x, int(y) + 4); cout << "/ == " << char(92);
		Console::SetCursorPosition(x, int(y) + 5); cout << "|/**" << char(92) << "|";
	}

	void dibujar_2() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, int(y)); cout << "|" << char(92) << "**/|";
		Console::SetCursorPosition(x, int(y) + 1); cout << char(92) << " == /";
		Console::SetCursorPosition(x, int(y) + 2); cout << " |  | ";
		Console::SetCursorPosition(x, int(y) + 3); cout << " |  | ";
		Console::SetCursorPosition(x, int(y) + 4); cout << " " << char(92) << "  / ";
		Console::SetCursorPosition(x, int(y) + 5); cout << "  " << char(92) << "/  ";
	}
};
