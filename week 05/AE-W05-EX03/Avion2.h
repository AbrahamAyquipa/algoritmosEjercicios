#pragma once
#include "Entidad.h"

class Avion2 : public Entidad
{
public:
	Avion2() : Entidad()
	{
		//ID = 2;
		ancho = 13; alto = 3;
		x = rand() % (ANCHO - ancho); y = rand() % (ALTO - alto);
	}
	void Mostrar()
	{
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "    __!__    ";
		Console::SetCursorPosition(x, y + 1); cout << "_____(_)_____";
		Console::SetCursorPosition(x, y + 2); cout << "   !  !  !   ";
	}
};
