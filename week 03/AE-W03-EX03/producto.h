#pragma once
#include <iostream>
using namespace std;

class producto {
private:
	int codigo_producto;
	string nombre;
	string tipo;
	string marca;
	int stock;
	float precio;
public:
	producto(int codigo_producto, string nombre, string tipo, string marca, int stock, float precio) {
		this->codigo_producto = codigo_producto;
		this->nombre = nombre;
		this->tipo = tipo;
		this->marca = marca;
		this->stock = stock;
		this->precio = precio;
	}

	~producto() { }

	void toString() {
		cout << "Id: " << this->codigo_producto << " | " << this->nombre << " | Type: " << this->tipo << " | Brand: " << this->marca << " | Stock: " << this->stock << " | Price: " << this->precio << '\n';
	}

	void agregarStock(int quantity) { this->stock += quantity; }
	void eliminarStock(int quantity) { this->stock -= quantity; }
	int getCodigoNombre() { return this->codigo_producto; }
	int getStock() { return this->stock; }
};
