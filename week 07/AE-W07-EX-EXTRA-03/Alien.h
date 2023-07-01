#pragma once
#include "Entidad.h"

//Alien es una clase derivada de la clase Entidad.

class Alien : public Entidad {
public:
	Alien(int px, float py, int pdx, int palto, int pancho) : Entidad(px, py, pdx, palto, pancho) {
		dy = 0.1 + (float(rand() % 10001 + 20000) / RAND_MAX);
	}
	~Alien() {}

	void borrar() {
		Console::SetCursorPosition(x, int(y)); cout << "           ";
		Console::SetCursorPosition(x, int(y) + 1); cout << "           ";
		Console::SetCursorPosition(x, int(y) + 2); cout << "           ";
	}

	void posicionar() {
		if (y < Console::WindowTop + 1 || y + alto > Console::WindowHeight) {
			dy *= -1;
		}
		y += dy;
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(x, int(y)); cout << "   .---.   ";
		Console::SetCursorPosition(x, int(y) + 1); cout << " _/__~0_" << char(92) << "_ ";
		Console::SetCursorPosition(x, int(y) + 2); cout << "(_________)";
	}
};
