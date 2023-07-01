#pragma once
#include "Entidad.h"

class Avion7 : public Entidad
{
public:
	Avion7() : Entidad()
	{
		//ID = 7;
		ancho = 19; alto = 3;
		x = rand() % (ANCHO - ancho); y = rand() % (ALTO - alto);
	}
	void Mostrar()
	{
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "       __|__       ";
		Console::SetCursorPosition(x, y + 1); cout << "________(*)________";
		Console::SetCursorPosition(x, y + 2); cout << "       o/ \\o       ";
	}
};
