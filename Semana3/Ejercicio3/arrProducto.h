#pragma once
#include "producto.h"

class arrProductos {
private:
	producto** arreglo_productos;
	int numero_productos;
public:
	arrProductos() {
		this->arreglo_productos = nullptr;
		this->numero_productos = 0;
	}

	~arrProductos() {
		for (int i = 0; i < this->numero_productos; ++i) {
			delete this->arreglo_productos[i];
		}
		delete[] arreglo_productos;
	}

	void agregarProducto(producto* obj) {
		producto** aux = new producto * [this->numero_productos + 1];

		for (int i = 0; i < this->numero_productos; ++i) {
			aux[i] = arreglo_productos[i];
		}

		aux[this->numero_productos] = obj;

		delete[] this->arreglo_productos;
		this->arreglo_productos = aux;

		++this->numero_productos;
	}

	producto* getProductoSegunPosicion(int posicion) {
		if (posicion < 0 || posicion >= this->numero_productos) throw "Error: Índice fuera de rango";
		return this->arreglo_productos[posicion];
	}

	int getNumeroProductos() {
		return this->numero_productos;
	}
};
