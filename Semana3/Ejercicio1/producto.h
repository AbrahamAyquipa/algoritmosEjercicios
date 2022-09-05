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

	
		this->arreglo_platos = aux;

		++this->numero_platos;
	}

	
			aux[actual] = this->arreglo_platos[i];
			++actual;
		}

		delete[] this->arreglo_platos;
		this->arreglo_platos = aux;

		--this->numero_platos;
	}

	void listaPlatos() {
		for (int i = 0; i < numero_platos; i++) {
			cout << "\tPosicion: " << i + 1 << " -> ";
			this->arreglo_platos[i]->toString();
		}
	}

	plato* getPlatosSegunPosicion(int posicion) {
		return this->arreglo_platos[posicion];
	}

	int getNumeroPlatos() {
		return this->numero_platos;
	}
};
