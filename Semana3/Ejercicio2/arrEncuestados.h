#pragma once
#include "encuestados.h"

class arrEncuestados {
private:
	encuesta** arreglo_encuestados;
	int numero_encuestados;
public:
	arrEncuestados() {
		this->arreglo_encuestados = nullptr;
		this->numero_encuestados = 0;
	}

	~arrEncuestados() {
		for (int i = 0; i < numero_encuestados; i++) {
			delete arreglo_encuestados[i];
		}
		delete[] arreglo_encuestados;
	}

	void generarEncuesta(encuesta* obj) {
		encuesta** aux = new encuesta * [numero_encuestados + 1];

		if (this->arreglo_encuestados != nullptr) {
			for (int i = 0; i < this->numero_encuestados; i++) {
				aux[i] = this->arreglo_encuestados[i];
			}
		}
		aux[this->numero_encuestados] = obj;

		if (this->arreglo_encuestados != nullptr) delete[] this->arreglo_encuestados;
		this->arreglo_encuestados = aux;

		++this->numero_encuestados;
	}

	void mostrarEncuesta() {
		for (int i = 0; i < numero_encuestados; i++) {
			this->arreglo_encuestados[i]->toString();
		}
	}

	void eliminarEncuesta(int posicion) {
		encuesta** aux = new encuesta * [this->numero_encuestados - 1];

		int actual = 0;

		if (arreglo_encuestados != nullptr) {
			for (int i = 0; i < this->numero_encuestados; i++) {
				if (i == posicion) continue;
				aux[actual] = this->arreglo_encuestados[i];
				++actual;
			}
		}

		if(this->arreglo_encuestados != nullptr) delete[] this->arreglo_encuestados;
		this->arreglo_encuestados = aux;

		--this->numero_encuestados;
	}

	int getNumeroEncuestados() {
		return this->numero_encuestados;
	}
};
