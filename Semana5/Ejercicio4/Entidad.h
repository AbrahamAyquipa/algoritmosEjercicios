#pragma once
#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;
using namespace System;

#define ANCHO 80
#define ALTO 20

class Entidad {
protected:
	int ID;
	int x, y;
	int ancho, alto;
	ConsoleColor color;

public:
	int GetX() { return x; }
	int GetY() { return y; }
	int GetAncho() { return ancho; }
	int GetAlto() { return alto; }
	int GetID() { return ID; }

	void SetX(int x) { this->x = x; }
	void SetY(int y) {this->y = y; }
	void SetAncho(int ancho) { this->ancho = ancho; }
	void SetAlto(int alto) { this->alto = alto; }
	void SetColor(ConsoleColor color) { this->color = color; }

	void Borrar() {
		for (int i = 0; i < alto; i++)
			for (int j = 0; j < ancho; j++) {
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
	}

	void Mover() { y++; }
};
