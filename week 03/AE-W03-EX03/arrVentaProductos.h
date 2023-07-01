#pragma once
#include "ventaProductos.h"

class arrVentaProductos {
private:
	ventaProductos** arreglo_venta_productos;
	int numero_ventas;
public:
	arrVentaProductos() {
		this->arreglo_venta_productos = nullptr;
		this->numero_ventas = 0;
	}

	~arrVentaProductos() {
		for (int i = 0; i < this->numero_ventas; ++i) {
			delete this->arreglo_venta_productos[i];
		}
		delete[] arreglo_venta_productos;
	}

	void agregarProducto(ventaProductos* obj) {
		ventaProductos** aux = new ventaProductos * [this->numero_ventas + 1];

		for (int i = 0; i < this->numero_ventas; ++i) {
			aux[i] = arreglo_venta_productos[i];
		}

		aux[this->numero_ventas] = obj;

		delete[] this->arreglo_venta_productos;
		this->arreglo_venta_productos = aux;

		++this->numero_ventas;
	}

	int getNumeroVentaProductos() {
		return this->numero_ventas;
	}

	ventaProductos* getVentaProductoSegunPosicion(int posicion) {
		if (posicion < 0 || posicion >= this->numero_ventas) throw "Error: Index out of range";
		return this->arreglo_venta_productos[posicion];
	}
};
