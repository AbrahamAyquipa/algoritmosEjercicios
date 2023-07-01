#pragma once
#include <iostream>
using namespace std;

class Cliente {
private:
	string DNI;
	string nombre;
public:
	Cliente(string DNI, string nombre) {
		this->DNI = DNI;
		this->nombre = nombre;
	}

	~Cliente() { }

	string getDNI() { return this->DNI; }
	string getNombre() { return this->nombre; }
};
