#pragma once
#include "contacto.h"
#include <iostream>
using namespace std;

class arrContactos {
private:
	contacto** arreglo_contactos;
	int numero_contactos;

public:
	arrContactos() {
		this->arreglo_contactos = nullptr;
		this->numero_contactos = 0;
	}

	~arrContactos() {
		for (int i = 0; i < numero_contactos; ++i) {
			delete this->arreglo_contactos[i];
		}
		delete[] this->arreglo_contactos;
	}

	void agregarContacto(contacto* obj) {
		contacto** aux = new contacto * [this->numero_contactos + 1];

		for (int i = 0; i < this->numero_contactos; ++i) {
			aux[i] = this->arreglo_contactos[i];
		}

		aux[this->numero_contactos] = obj;

		delete[] this->arreglo_contactos;
		this->arreglo_contactos = aux;

		++this->numero_contactos;
	}

	void eliminarContacto(int posicion) {
		contacto** aux = new contacto * [this->numero_contactos - 1];

		int actual = 0;
		for (int i = 0; i < this->numero_contactos; ++i) {
			if (i == posicion) continue;
			aux[actual] = this->arreglo_contactos[i];
			++actual;
		}

		delete[] this->arreglo_contactos;
		this->arreglo_contactos = aux;

		--this->numero_contactos;
	}

	void listaContactos() {
		for (int i = 0; i < this->numero_contactos; ++i) {
			cout << "\tPosicion: " << i << " -> ";
			this->arreglo_contactos[i]->toString();
		}
	}

	void listaContactosCumpleañosMayo() {
		for (int i = 0; i < this->numero_contactos; ++i) {
			string fecha_nacimiento = this->arreglo_contactos[i]->getFechaNacimiento();

			if (fecha_nacimiento == "mayo") {
				cout << "\tPosicion: " << i << " -> ";
				this->arreglo_contactos[i]->toString();
			}
		}
	}

	void listaContactosVarones() {
		for (int i = 0; i < this->numero_contactos; ++i) {
			char sexo = toupper(this->arreglo_contactos[i]->getSexo());
			if (sexo == 'M') {
				cout << "\tPosicion: " << i << " -> ";
				this->arreglo_contactos[i]->toString();
			}
		}
	}

	void listaContactosQueTienenFbYWhtsp() {
		for (int i = 0; i < this->numero_contactos; ++i) {
			string red_social = this->arreglo_contactos[i]->getRedSocial();

			if (red_social == "whatsapp" || red_social == "facebook") {
				cout << "\tPosicion: " << i << " -> ";
				this->arreglo_contactos[i]->toString();
			}
		}
	}

	contacto* getContactos(int posicion) {
		return this->arreglo_contactos[posicion];
	}

	int getNumeroContactos() {
		return this->numero_contactos;
	}
};
