#pragma once
#include "Entidad.h"

class Gamma : public Entidad
{
public:
	Gamma()
	{
		ID = 3;
		ancho = 19; alto = 10;
		x = ANCHO - ancho; y = 0;
		color = ConsoleColor::Green;
	}
	void Mostrar()
	{
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "         .         ";
		Console::SetCursorPosition(x, y + 1); cout << "         |         ";
		Console::SetCursorPosition(x, y + 2); cout << "     .-\" ^ \"-.     ";
		Console::SetCursorPosition(x, y + 3); cout << "    /_......._\\    ";
		Console::SetCursorPosition(x, y + 4); cout << " .-\"`         `\"-. ";
		Console::SetCursorPosition(x, y + 5); cout << "(  ooo  ooo  ooo  )";
		Console::SetCursorPosition(x, y + 6); cout << " '-.,_________,.-' ";
		Console::SetCursorPosition(x, y + 7); cout << "     /       \\     ";
		Console::SetCursorPosition(x, y + 8); cout << "   _/         \\_   ";
		Console::SetCursorPosition(x, y + 9); cout << "  `\"`         `\"`  ";
	}
};
