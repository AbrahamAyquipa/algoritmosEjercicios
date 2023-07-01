#pragma once
#include "iostream"
#include "time.h"
using namespace std;
using namespace System;

class Vehiculo
{
protected:
	double x;
	int y; 
	double velocidad;// dx
public:
	Vehiculo(double px, int py);
	~Vehiculo();
	void borrar();
	void mover();
	void dibujar(short elegido);
};

//IMPLMENTACION
Vehiculo::Vehiculo(double px, int py)
{
	
	this->x = px;
	this->y = py;

	velocidad = 0.1 + (rand() % 10) / 10.0;
}

Vehiculo::~Vehiculo()
{}

void Vehiculo::borrar()
{
	Console::SetCursorPosition(x, y); cout << "      ";
	Console::SetCursorPosition(x, y+1); cout << "      ";
	Console::SetCursorPosition(x, y+2); cout << "      ";
}
void Vehiculo::mover()
{
	x += velocidad;
}

void Vehiculo::dibujar(short elegido)
{
	//DYNAMIC
	if(elegido ==1 )
	{
		Console::SetCursorPosition(x, y);   cout << "__";
		Console::SetCursorPosition(x, y+1); cout << "|_\\_";
		Console::SetCursorPosition(x, y+2); cout << "Lo_oJ";
	}

	if (elegido == 2)
	{
		Console::SetCursorPosition(x, y); cout << "   __";
		Console::SetCursorPosition(x, y+1); cout << " _| = \\__";
		Console::SetCursorPosition(x, y+2); cout << "/_o____o_\\";
	}
	//LEGER
	if (elegido == 3)
	{
		Console::SetCursorPosition(x, y);   cout << "__";
		Console::SetCursorPosition(x, y+1); cout << ".-'--`-._ ";
		Console::SetCursorPosition(x, y+2); cout << "'-O---O--'";
	}

	if (elegido == 4)
	{
		Console::SetCursorPosition(x, y);	cout << ".-'--`-._";
		Console::SetCursorPosition(x, y + 1);   cout << "'-O---O--'";
	}
}
