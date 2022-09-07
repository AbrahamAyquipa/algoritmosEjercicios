#pragma once
#include <iostream>
using namespace std;

class Producto {
private:
	string nombre;
	string marca;
	string modelo;
	int stock;
	string color;
	double precio;
public:
	Producto(string nombre, string marca, string modelo, int stock, string color, double precio);
	~Producto();

	string getNombre();
	string getMarca();
	string getModelo();
	int getStock();
	string getColor();
	double getPrecio();

	void setNombre(string nombre);
	void setMarca(string marca);
	void setModelo(string modelo);
	void setStock(int stock);
	void setColor(string color);
	void setPrecio(double precio);

	void toString();
};

Producto::Producto(string nombre, string marca, string modelo, int stock, string color, double precio) {
	this->nombre = nombre;
	this->marca = marca;
	this->modelo = modelo;
	this->stock = stock;
	this->color = color;
	this->precio = precio;
}

Producto::~Producto() {};

string Producto::getNombre() { return this->nombre; }
string Producto::getMarca() { return this->marca; }
string Producto::getModelo() { return this->modelo; }
int Producto::getStock() { return this->stock; }
string Producto::getColor() { return this->color; }
double Producto::getPrecio() { return this->precio; }

void Producto::setNombre(string nombre) { this->nombre = nombre; }
void Producto::setMarca(string marca) { this->marca = marca; }
void Producto::setModelo(string modelo) { this->modelo = modelo; }
void Producto::setStock(int stock) { this->stock = stock; }
void Producto::setColor(string color) { this->color = color; }
void Producto::setPrecio(double precio) { this->precio = precio; }

void Producto::toString() {
	cout << this->nombre << "\t" << this->marca << "\t" << this->modelo << "\t" << this->stock << "\t" << this->color << "\t" << this->precio << "\n";
}
