#pragma once
#include "venta.h"

class arrVentas {
private:
	venta** arreglo_ventas;
	int numero_ventas;
public:
	arrVentas() {
		this->arreglo_ventas = nullptr;
		this->numero_ventas = 0;
	}

	~arrVentas() {
		for (int i = 0; i < this->numero_ventas; ++i) {
			delete this->arreglo_ventas[i];
		}
		delete[] arreglo_ventas;
	}

	void agregarVenta(venta* obj) {
		venta** aux = new venta * [this->numero_ventas + 1];

		for (int i = 0; i < this->numero_ventas; ++i) {
			aux[i] = arreglo_ventas[i];
		}

		aux[this->numero_ventas] = obj;

		delete[] this->arreglo_ventas;
		this->arreglo_ventas = aux;

		++this->numero_ventas;
	}

	int getNumeroVentas() {
		return this->numero_ventas;
	}

	venta* getVentaSegunPosicion(int posicion) {
		if (posicion < 0 || posicion >= this->numero_ventas) throw "Error: Índice fuera de rango";
		return this->arreglo_ventas[posicion];
	}
};
