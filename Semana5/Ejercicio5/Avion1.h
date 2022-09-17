#pragma once
#include "Entidad.h"

class Avion1 : public Entidad
{
public:
	Avion1() : Entidad()
	{
		//ID = 1;
		ancho = 11; alto = 3;
		x = rand() % (ANCHO - ancho); y = rand() % (ALTO - alto);
	}
	void Mostrar()
	{
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "-----------";
		Console::SetCursorPosition(x, y + 1); cout << "_\\__(_)__/_";
		Console::SetCursorPosition(x, y + 2); cout << "   ./ \\.   ";
	}
};
