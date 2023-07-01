#pragma once
#include "Entidad.h"

class Avion9 : public Entidad
{
public:
	Avion9() : Entidad()
	{
		//ID = 9;
		ancho = 16; alto = 4;
		x = rand() % (ANCHO - ancho); y = rand() % (ALTO - alto);
	}
	void Mostrar()
	{
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "   ____       _ ";
		Console::SetCursorPosition(x, y + 1); cout << "| __\\_\\_o____/_|";
		Console::SetCursorPosition(x, y + 2); cout << "<[___\\_\\_-----< ";
		Console::SetCursorPosition(x, y + 3); cout << "|               ";

	}
};
