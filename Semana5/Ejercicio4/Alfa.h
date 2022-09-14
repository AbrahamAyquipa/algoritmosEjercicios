#pragma once
#include "Entidad.h"

class Alfa : public Entidad {
public:
	Alfa() {
		ID = 1;
		x = 0;   y = 0;
		ancho = 21; alto = 5;
		color = ConsoleColor::Red;
	}

	void Mostrar() {
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "       _.---._       ";
		Console::SetCursorPosition(x, y + 1); cout << "     .'       '.     ";
		Console::SetCursorPosition(x, y + 2); cout << " _.-~===========~-._ ";
		Console::SetCursorPosition(x, y + 3); cout << "(___________________)";
		Console::SetCursorPosition(x, y + 4); cout << "      \\_______/      ";
	}
};
