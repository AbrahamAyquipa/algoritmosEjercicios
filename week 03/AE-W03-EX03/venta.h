#pragma once
#include <iostream>
using namespace std;
#include "arrVentaProductos.h"

class venta {
private:
	int codigo_venta;
	string fecha;
	string codigo_cliente;
	arrVentaProductos* objArrVentaProductos;
public:
	venta(int codigo_venta, string fecha, string codigo_cliente, arrVentaProductos* objArrVentaProductos) {
		this->codigo_venta = codigo_venta;
		this->fecha = fecha;
		this->codigo_cliente = codigo_cliente;
		this->objArrVentaProductos = objArrVentaProductos;
	}

	~venta() {
		delete objArrVentaProductos;
	}

	void toString() {
		cout << "\tSale Id: " << this->codigo_venta << '\n';
		cout << "\tDate: " << this->fecha << '\n';
		cout << "\tClient Id: " << this->codigo_cliente << '\n';
		cout << "\tProducts:\n";
		for (int i = 0; i < objArrVentaProductos->getNumeroVentaProductos(); ++i) {
			cout << "\t\tID: " << objArrVentaProductos->getVentaProductoSegunPosicion(i)->getCodigoProducto() << " - QUANTITY: " << objArrVentaProductos->getVentaProductoSegunPosicion(i)->getCantidad() << '\n';
		}
		cout << '\n';
	}
};
