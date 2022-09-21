#pragma once
#include<iostream>
#include <conio.h>
#include <time.h>

using namespace std;
using namespace System;

#define ANCHO 80
#define ALTO 30

class Entidad {
protected:
	//int ID;
	int x, y;
	int dx, dy;
	int alto, ancho;
	ConsoleColor color;
public:
	Entidad() {
		dx = rand() % 5 + 1; 
		dy = rand() % 5 + 1;
		color = (ConsoleColor)(rand() % 15 + 1);
	}
	
	int GetX() {
		return x;
	}
	
	int GetY() {
		return y;
	}
	
	int GetDX()
	{
		return dx;
	}
	int GetDY()
	{
		return dy;
	}
	
	int GetAlto() {
		return alto;
	}
	int GetAncho() {
		return ancho;
	}
	int GetID()
	{
		//return ID;
	}

	void SetX(int x)
	{
		this->x = x;
	}
	void SetY(int y)
	{
		this->y = y;
	}
	void SetDX(int dx)
	{
		this->dx = dx;
	}
	void SetDY(int dy)
	{
		this->dy = dy;
	}
	void SetAlto(int alto)
	{
		this->alto = alto;
	}
	void SetAncho(int ancho)
	{
		this->ancho = ancho;
	}

	void Borrar()
	{
		for (int i = 0; i < alto; i++)
			for (int j = 0; j < ancho; j++)
			{
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
	}
	
	void Mover() {
		if (x + dx < 0 || x + ancho + dx >= ANCHO)
			dx *= -1;

		if (y + dy < 0 || y + alto + dy >= ALTO)
			dy *= -1;

		x += dx;
		y += dy;
	}
	
	virtual void Mostrar() {
		cout << "CLASE ENTIDAD";
	}
};
