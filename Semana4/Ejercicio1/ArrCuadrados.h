#pragma once
#include <conio.h>
#include "Cuadrado.h"

using namespace System;

class ArrCuadrados
{
private:
	Cuadrado** arreglo_cuadrados;
	int numero_cuadrados; // tamaño delarreglo

public:
	ArrCuadrados();
	~ArrCuadrados();

	void AgregarCuadrado(Cuadrado* obj);
	void MostrarCuadrado();
	void EliminarCuadrado();
	void CambiarColor();

	int getNumeroCuadrados();

};

ArrCuadrados::ArrCuadrados(){
	numero_cuadrados = 0;
	arreglo_cuadrados = new Cuadrado * [numero_cuadrados];
}

ArrCuadrados::~ArrCuadrados() {}

void ArrCuadrados::AgregarCuadrado(Cuadrado* obj) {
	Cuadrado** aux = new Cuadrado * [numero_cuadrados + 1];

	if (arreglo_cuadrados != nullptr) {
		for (int i = 0; i < numero_cuadrados; i++) {
			aux[i] = arreglo_cuadrados[i];
		}
		aux[numero_cuadrados] = obj;

		numero_cuadrados = numero_cuadrados + 1;

		if (arreglo_cuadrados != nullptr) delete[] arreglo_cuadrados;
		arreglo_cuadrados = aux;

	}
}

void ArrCuadrados::EliminarCuadrado() {
	arreglo_cuadrados[0]->borrar_cuadrados();
	Cuadrado** aux = new Cuadrado * [numero_cuadrados - 1];

	for (int i = 0; i < numero_cuadrados - 1; i++) {
		aux[i] = arreglo_cuadrados[i + 1];
	}
	numero_cuadrados = numero_cuadrados - 1;
	arreglo_cuadrados = aux;
}

void ArrCuadrados::MostrarCuadrado() {
	for (int i = 0; i < numero_cuadrados; i++) {
		arreglo_cuadrados[i]->borrar_cuadrados();
		arreglo_cuadrados[i]->mover_cuadrados();
		arreglo_cuadrados[i]->imprimir_cuadrados();
	}
}

void ArrCuadrados::CambiarColor() {
	for (int i = 0; i < numero_cuadrados; i++) {
		arreglo_cuadrados[i]->nuevoColor();
	}
}

int ArrCuadrados::getNumeroCuadrados() {
	return this->numero_cuadrados;
}
