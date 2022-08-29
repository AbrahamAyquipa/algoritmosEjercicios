#pragma once
#include "plato.h"
#include <iostream>
using namespace std;

class arrPlato {
private:
	plato** arreglo_platos;
	int numero_platos;

public:
	arrPlato() {
		this->arreglo_platos = nullptr;
		this->numero_platos = 0;
	}

	~arrPlato() {
		for (int i = 0; i < numero_platos; ++i) {
			delete this->arreglo_platos[i];
		}
		delete[] this->arreglo_platos;
	}

	void agregarPlato(plato* obj) {
		plato** aux = new plato * [this->numero_platos + 1];

		for (int i = 0; i < this->numero_platos; ++i) {
			aux[i] = this->arreglo_platos[i];
		}

		aux[this->numero_platos] = obj;

		delete[] this->arreglo_platos;
		this->arreglo_platos = aux;

		++this->numero_platos;
	}

	void eliminarPlato(int posicion) {
		plato** aux = new plato * [this->numero_platos - 1];

		int actual = 0;
		for (int i = 0; i < this->numero_platos; ++i) {
			if (i == posicion) continue;
			aux[actual] = this->arreglo_platos[i];
			++actual;
		}

		delete[] this->arreglo_platos;
		this->arreglo_platos = aux;

		--this->numero_platos;
	}

	void listaPlatos() {
		for (int i = 0; i < numero_platos; i++) {
			cout << "\tPosicion: " << i << " -> ";
			this->arreglo_platos[i]->toString();
		}
	}

	void reportePicante() {
		for (int i = 0; i < numero_platos; i++) {
			if (arreglo_platos[i]->getPicante() == true)
				cout << "\tPosicion: " << i << " -> ";
			this->arreglo_platos[i]->toString();
		}
	}

	void reportemas100() {
		for (int i = 0; i < numero_platos; i++) {
			if (arreglo_platos[i]->getPrecio() > 100)
				cout << "\tPosicion: " << i << " -> ";
			this->arreglo_platos[i]->toString();
		}
	}

	plato* getPlatos(int posicion) {
		return this->arreglo_platos[posicion];
	}

	int getNumeroPlatos() {
		return this->numero_platos;
	}
};
