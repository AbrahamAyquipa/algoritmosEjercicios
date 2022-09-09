#pragma once
#include "cliente.h"

class arrClientes {
private:
	Cliente** arreglo_clientes;
	int numero_clientes;
public:
	arrClientes() {
		this->arreglo_clientes = nullptr;
		this->numero_clientes = 0;
	}

	~arrClientes() {
		for (int i = 0; i < this->numero_clientes; ++i) {
			delete this->arreglo_clientes[i];
		}
		delete[] arreglo_clientes;
	}

	void agregarCliente(Cliente* obj) {
		Cliente** aux = new Cliente * [this->numero_clientes + 1];

		for (int i = 0; i < this->numero_clientes; ++i) {
			aux[i] = arreglo_clientes[i];
		}

		aux[this->numero_clientes] = obj;

		delete[] this->arreglo_clientes;
		this->arreglo_clientes = aux;

		++this->numero_clientes;
	}

	Cliente* getClienteSegunPosicion(int posicion) {
		if (posicion < 0 || posicion >= this->numero_clientes) throw "Error: Índice fuera de rango";
		return this->arreglo_clientes[posicion];
	}

	int getNumeroClientes() {
		return this->numero_clientes;
	}
};
