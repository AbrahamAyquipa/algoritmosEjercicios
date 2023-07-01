#pragma once
#include "Entidad.h"

class Beta : public Entidad {
public:
	Beta(){
		ID = 2;
		ancho = 11; alto = 3;
		x = (ANCHO / 2) - (ancho / 2);     y = 0;
		color = ConsoleColor::Yellow;
	}

	void Mostrar() {
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "   .---.   ";
		Console::SetCursorPosition(x, y + 1); cout << " _/__~0_\\_ ";
		Console::SetCursorPosition(x, y + 2); cout << "(_________)";
	}
};
