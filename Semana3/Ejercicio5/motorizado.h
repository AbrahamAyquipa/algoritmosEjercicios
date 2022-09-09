#pragma once
#include <iostream>
using namespace std;

class motorizado {
private:
	string nombre;
	string apellido;
	string placa;
	float kilometraje;
	float precio;
	string empresa;
public:
motorizado(string name, std::string lastName, std::string plate, float mileage, std::string enterprise) {
	this->nombre = name;
	this->apellido = lastName;
	this->placa = plate;
	this->kilometraje = mileage;
	this->empresa = enterprise;
	this->precio = 1.5 * this->kilometraje;
}

~motorizado() { }

void toString() {
	cout << "{ Name: " << this->nombre << ' ' << this->apellido << " - Plate: " << this->placa << " - " << this->kilometraje << " KM - Enterprise: " << this->empresa << " - Price: $" << this->precio << " }\n";
}

std::string getEmpresa() {
	return this->empresa;
}
};
