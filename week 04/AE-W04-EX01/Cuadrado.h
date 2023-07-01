#pragma once
#include <iostream>

using namespace std;
using namespace System;

class Cuadrado {
private:
	char forma;
	short x, y;
	short dx, dy;
	int color;
public:
	Cuadrado();
	~Cuadrado();
	void nuevoColor();
	void imprimir_cuadrados();
	void mover_cuadrados();
	void borrar_cuadrados();
};

Cuadrado::Cuadrado() {
	x = y = 0;
	dx = dy = 0;
	forma = 4;

	System::Random numero_random;
	color = numero_random.Next(1, 16);
}

Cuadrado::~Cuadrado() {}

void Cuadrado::nuevoColor() {
	color = rand() % 10;
}

void Cuadrado::borrar_cuadrados() {
	Console::SetCursorPosition(x, y); cout << " ";
	Console::SetCursorPosition(x + 1, y); cout << " ";
	Console::SetCursorPosition(x, y + 1); cout << " ";
	Console::SetCursorPosition(x + 1, y + 1); cout << " ";
}

void Cuadrado::mover_cuadrados() {
	if (x == 0 && y == 0) { dx = 1; dy = 0; }
	if (x == 58 && y == 0) { dx = 0; dy = 1; }
	if (x == 58 && y == 18) { dx = -1; dy = 0; }
	if (x == 0 && y == 18) { dx = 0; dy = -1; }
	x += dx;
	y += dy;
}

void Cuadrado::imprimir_cuadrados() {
	System::Console::ForegroundColor = (System::ConsoleColor)this->color;
	Console::SetCursorPosition(x, y); cout << (char)forma;
	Console::SetCursorPosition(x + 1, y); cout << (char)forma;
	Console::SetCursorPosition(x, y + 1); cout << (char)forma;
	Console::SetCursorPosition(x + 1, y + 1); cout << (char)forma;
}
