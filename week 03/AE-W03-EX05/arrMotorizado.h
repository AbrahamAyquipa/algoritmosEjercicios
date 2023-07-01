#pragma once
#include "motorizado.h"

class arrMotorizado {
private:
	motorizado** arrMotorizados;
	int numero_motorizados;
public:
	arrMotorizado() {
		this->arrMotorizados = nullptr;
		this->numero_motorizados = 0;
	}

	~arrMotorizado() {
		for (int i = 0; i < this->numero_motorizados; ++i) {
			delete this->arrMotorizados[i];
		}
		delete[] this->arrMotorizados;
	}

	void agregarMotorizado(motorizado* newDriver) {
		motorizado** temp = new motorizado * [this->numero_motorizados + 1];

		for (int i = 0; i < this->numero_motorizados; ++i) {
			temp[i] = this->arrMotorizados[i];
		}

		temp[this->numero_motorizados] = newDriver;

		delete[] this->arrMotorizados;
		this->arrMotorizados = temp;

		++this->numero_motorizados;
	}

	void eliminarMotorizado(int pos) {
		if (pos < 0 || pos >= this->numero_motorizados || this->numero_motorizados == 0) return;

		motorizado** temp = new motorizado * [this->numero_motorizados - 1];

		int j = 0;
		for (int i = 0; i < this->numero_motorizados; ++i) {
			if (i == pos) continue;
			temp[j++] = this->arrMotorizados[i];
		}

		delete[] this->arrMotorizados;
		this->arrMotorizados = temp;

		--this->numero_motorizados;
	}

	void mostrarTodosMotorizados() {
		for (int i = 0; i < this->numero_motorizados; ++i) {
			this->arrMotorizados[i]->toString();
		}
	}

	void mostrarTodosMotorizadosMapi() {
		for (int i = 0; i < this->numero_motorizados; ++i) {
			if (this->arrMotorizados[i]->getEmpresa() == "Mapi") {
				this->arrMotorizados[i]->toString();
			}
		}
	}

	void mostrarTodosMotorizadosGlopo() {
		for (int i = 0; i < this->numero_motorizados; ++i) {
			if (this->arrMotorizados[i]->getEmpresa() == "Glopo") {
				this->arrMotorizados[i]->toString();
			}
		}
	}

	int getNumeroMotorizados() {
		return this->numero_motorizados;
	}
};
