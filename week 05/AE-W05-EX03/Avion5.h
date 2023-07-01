#pragma once
#include "Entidad.h"
class Avion5 : public Entidad
{
public:
	Avion5() : Entidad()
	{
		//ID = 5;
		ancho = 13; alto = 3;
		x = rand() % (ANCHO - ancho); y = rand() % (ALTO - alto);
	}
	void Mostrar()
	{
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "    __!__    ";
		Console::SetCursorPosition(x, y + 1); cout << "-----<*>-----";
		Console::SetCursorPosition(x, y + 2); cout << "    o O o    ";
	}
};
