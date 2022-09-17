#pragma once
#include "Entidad.h"
class Avion8 : public Entidad
{
public:
	Avion8() : Entidad()
	{
		//ID = 8;
		ancho = 17; alto = 4;
		x = rand() % (ANCHO - ancho); y = rand() % (ALTO - alto);
	}
	void Mostrar()
	{
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "        .        ";
		Console::SetCursorPosition(x, y + 1); cout << "._______|_______.";
		Console::SetCursorPosition(x, y + 2); cout << "      \(*)/      ";
		Console::SetCursorPosition(x, y + 3); cout << "      o/ \\o      ";
	}
};
