#pragma once
#include <iostream>
#include <string>
using namespace std;

class plato {
private:
	string nombre;
	int frioOCaliente;
	bool picante;
	double calorias;
	double precio;

public:
	plato(string nombre, int frioOCaliente, bool picante, double calorias, double precio);
	~plato();

	//Get
	string getNombre();
	bool getFrioOCaliente();
	bool getPicante();
	float getCalorias();
	float getPrecio();
	//Set
	void setNombre(string nombre);
	void setFrioOCaliente(int frioOCaliente);
	void setPicante(bool picante);
	void setCalorias(double calorias);
	void setPrecio(double precio);

	void toString();
};

plato::plato(string nombre, int frioOCaliente, bool picante, double calorias, double precio) {
	this->nombre = nombre;
	this->frioOCaliente = frioOCaliente;
	this->picante = picante;
	this->calorias = calorias;
	this->precio = precio;
}

plato::~plato() {}

string plato::getNombre() { return nombre; }
bool plato::getFrioOCaliente() { return frioOCaliente; }
bool plato::getPicante() { return picante; }
float plato::getCalorias() { return calorias; }
float plato::getPrecio() { return precio; }

void plato::setNombre(string nombre) { this->nombre = nombre; };
void plato::setFrioOCaliente(int frioOCaliente) { this->frioOCaliente = frioOCaliente; };
void plato::setPicante(bool picante) { this->picante = picante; };
void plato::setCalorias(double calorias) { this->calorias = calorias; };
void plato::setPrecio(double precio) { this->precio = precio; };

void plato::toString() {
	cout << "NOMBRE: " << this->nombre << " | FRIO O CALIENTE: " << this->frioOCaliente << " | PICANTE: " << this->picante << " | CALORIAS" << this->calorias << " | PRECIO " << this->precio << endl;
}
