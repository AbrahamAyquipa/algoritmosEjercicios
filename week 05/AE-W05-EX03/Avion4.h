#pragma once
#include "Entidad.h"
class Avion4 : public Entidad
{
public:
	Avion4() : Entidad()
	{
		//ID = 4;
		ancho = 17; alto = 3;
		x = rand() % (ANCHO - ancho); y = rand() % (ALTO - alto);
	}
	void Mostrar()
	{
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "________|________";
		Console::SetCursorPosition(x, y + 1); cout << " _|_____0_____|_ ";
		Console::SetCursorPosition(x, y + 2); cout << "      |   |      ";
	}
};
