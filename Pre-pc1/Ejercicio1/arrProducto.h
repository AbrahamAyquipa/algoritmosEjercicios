#pragma once
#include "Producto.h"

class ArrProducto {
private:
	Producto** arreglo_productos;
	int numero_productos;
public:
	ArrProducto();
	~ArrProducto();

	void agregarProductos(Producto* obj);
	void eliminarProducto(int posicion);
	void listaProductos();
	void reportePorMarca(string marca);
	void reporteStock();
	Producto* getPorductoSegunPosicion(int posicion);
	int getNumeroArreglo();
};

ArrProducto::ArrProducto() {
	this->arreglo_productos = nullptr;
	this->numero_productos = 0;
}

ArrProducto ::~ArrProducto() {
	for (int i = 0; i < this->numero_productos; i++) {
		delete this->arreglo_productos[i];
	}
	delete[] this->arreglo_productos;
}

void ArrProducto::agregarProductos(Producto* obj) {
	Producto** aux = new Producto * [this->numero_productos + 1];

	if (this->arreglo_productos != nullptr) {
		for (int i = 0; i < this->numero_productos; i++) {
			aux[i] = this->arreglo_productos[i];
		}
	}
	aux[this->numero_productos] = obj;

	if (this->arreglo_productos != nullptr) delete[] this->arreglo_productos;
	this->arreglo_productos = aux;

	++this->numero_productos;
}

void ArrProducto::eliminarProducto(int posicion) {
	Producto** aux = new Producto * [this->numero_productos - 1];

	int actual = 0;
	if (this->arreglo_productos != nullptr) {
		for (int i = 0; i < this->numero_productos; i++) {
			if (i == posicion) continue;
			aux[actual] = this->arreglo_productos[i];
			++actual;
		}
	}

	if (this->arreglo_productos != nullptr) delete[] this->arreglo_productos;
	this->arreglo_productos = aux;

	--this->numero_productos;
}

void ArrProducto::listaProductos() {
	cout << "Nombre\tMarca\tModelo\tStock\tColor\tPrecio\n";
	for (int i = 0; i < this->numero_productos; i++) {
		this->arreglo_productos[i]->toString();
	}
}

void ArrProducto::reportePorMarca(string marca) {
	for (int i = 0; i < this->numero_productos; i++) {
		if (this->arreglo_productos[i]->getMarca() == marca) {
			this->arreglo_productos[i]->toString();
		}
	}
}

void ArrProducto::reporteStock() {
	for (int i = 0; i < this->numero_productos; i++) {
		if (this->arreglo_productos[i]->getStock() > 10) {
			this->arreglo_productos[i]->toString();
		}
	}
}

Producto* ArrProducto::getPorductoSegunPosicion(int posicion) {
	return this->arreglo_productos[posicion];
}

int ArrProducto::getNumeroArreglo() {
	return this->numero_productos;
}
