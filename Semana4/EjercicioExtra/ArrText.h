#pragma once
#include "Texto.h"

class ArrTexto {
private:
	Texto** arreglo_texto;
	int numero_textos;
public:
	ArrTexto() {
		this->arreglo_texto = nullptr;
		this->numero_textos = 0;
	}

	~ArrTexto() {
		for (int i = 0; i < this->numero_textos; ++i) {
			delete this->arreglo_texto[i];
		}
		delete[] this->arreglo_texto;
	}

	void agregarTexto(Texto* txt) {
		Texto** temp = new Texto * [this->numero_textos + 1];

		for (int i = 0; i < this->numero_textos; ++i) {
			temp[i] = this->arreglo_texto[i];
		}

		temp[this->numero_textos] = txt;

		delete[] this->arreglo_texto;
		this->arreglo_texto = temp;

		++this->numero_textos;
	}

	void eliminarTexto() {
		if (this->numero_textos == 0) return;

		this->arreglo_texto[this->numero_textos - 1]->borrar();
		Texto** temp = new Texto * [this->numero_textos - 1];

		for (int i = 0; i < this->numero_textos - 1; ++i) {
			temp[i] = this->arreglo_texto[i];
		}

		delete[] this->arreglo_texto;
		this->arreglo_texto = temp;

		--this->numero_textos;
	}

	void mostrarTextos(int width, int height) {
		for (int i = 0; i < this->numero_textos; ++i) {
			this->arreglo_texto[i]->borrar();
			this->arreglo_texto[i]->mover(width, height);
			this->arreglo_texto[i]->imprimir();
		}
	}
};
