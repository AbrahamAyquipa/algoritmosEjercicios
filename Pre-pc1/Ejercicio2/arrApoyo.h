#pragma once
#include "Apoyo.h"

class ArrApoyo {
private:
	Apoyo** arreglo_apoyo;
	int numero_apoyo;
public:
	ArrApoyo();
	~ArrApoyo();

	void agregarRegistro(Apoyo* obj);
	void eliminarRegistro(int posicion);
	void listaApoyo();
	void reporteBecariosVacaciones();
	void reporteHospedajeMayor100();
	void reporteBecariosConPasajeAvion();
	void busquedaBecario(int codigo);
	Apoyo* getApoyoSegunPosicion(int posicion);
	int getNumeroApoyo();
};

ArrApoyo::ArrApoyo() {
	this->arreglo_apoyo = nullptr;
	this->numero_apoyo = 0;
}

ArrApoyo::~ArrApoyo() {
	for (int i = 0; i < this->numero_apoyo; i++) {
		delete this->arreglo_apoyo[i];
	}
	delete[] this->arreglo_apoyo;
}

void ArrApoyo::agregarRegistro(Apoyo* obj) {
	Apoyo** aux = new Apoyo * [this->numero_apoyo + 1];

	if (this->arreglo_apoyo != nullptr) {
		for (int i = 0; i < this->numero_apoyo; i++) {
			aux[i] = this->arreglo_apoyo[i];
		}
	}
	aux[this->numero_apoyo] = obj;

	if (this->arreglo_apoyo != nullptr) delete[] arreglo_apoyo;
	this->arreglo_apoyo = aux;

	++this->numero_apoyo;
}

void ArrApoyo::eliminarRegistro(int posicion) {
	Apoyo** aux = new Apoyo * [this->numero_apoyo - 1];

	int actual = 0;
	if (this->arreglo_apoyo != nullptr) {
		for (int i = 0; i < this->numero_apoyo; i++) {
			if (i == posicion) continue;
			aux[actual] =this->arreglo_apoyo[i];
			++actual;
		}
	}
	
	if (this->arreglo_apoyo != nullptr) delete[] this->arreglo_apoyo;
	this->arreglo_apoyo = aux;

	--this->arreglo_apoyo;
}

void ArrApoyo::reporteBecariosVacaciones() {
	for (int i = 0; i < this->numero_apoyo; i++) {
		if (this->arreglo_apoyo[i]->getEstadoBecario() == 'V') {
			this->arreglo_apoyo[i]->toString();
		}
	}
}

void ArrApoyo::reporteHospedajeMayor100() {
	for (int i = 0; i < this->numero_apoyo; i++) {
		if (this->arreglo_apoyo[i]->getHospedaje() > 100 == 'V') {
			this->arreglo_apoyo[i]->toString();
		}
	}
}

void ArrApoyo::reporteBecariosConPasajeAvion() {
	for (int i = 0; i < this->numero_apoyo; i++) {
		if (this->arreglo_apoyo[i]->getPasajeVueloAvion()) {
			this->arreglo_apoyo[i]->toString();
		}
	}
}

void ArrApoyo::busquedaBecario(int codigo) {
	for (int i = 0; i < this->numero_apoyo; i++) {
		if (this->arreglo_apoyo[i]->getPasajeVueloAvion()) {
			this->arreglo_apoyo[i]->toString();
		}
	}
}

void ArrApoyo::listaApoyo() {
	cout << "Codigo\tHospe\tPasaje\tEstado\n";
	for (int i = 0; i < this->numero_apoyo; i++) {
		this->arreglo_apoyo[i]->toString();
	}
}

Apoyo* ArrApoyo::getApoyoSegunPosicion(int posicion) {
	return this->arreglo_apoyo[posicion];
}

int ArrApoyo::getNumeroApoyo() {
	return this->numero_apoyo;
}
