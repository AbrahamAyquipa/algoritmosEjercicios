#pragma once
#include "Entidad.h"

class Avion6 : public Entidad
{
public:
	Avion6() : Entidad()
	{
		//ID = 6;
		ancho = 17; alto = 2;
		x = rand() % (ANCHO - ancho); y = rand() % (ALTO - alto);
	}
	void Mostrar()
	{
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "      \\ . /      ";
		Console::SetCursorPosition(x, y + 1); cout << ".______(*)______.";
	}
};
