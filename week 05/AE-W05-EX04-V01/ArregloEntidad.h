#pragma once
#include "Entidad.h"
#include "Alfa.h"
#include "Beta.h"
#include "Gamma.h"

class ArregloEntidad {
private:
	int cant;
	Entidad** arreglo;
	int alfa, beta;

public:
	ArregloEntidad() {
		alfa = beta = 0;
		cant = 0;
	}

	~ArregloEntidad() {
		for (int i = 0; i < cant; i++)
			delete arreglo[i];
		delete[] arreglo;
	}

	void Agregar(Entidad* nuevo) {
		if (nuevo->GetID() == 1) alfa++;

		if (alfa == 2) {
			alfa = 0;
			Agregar(new Beta());
		}

		if (nuevo->GetID() == 2) beta++;

		if (beta == 2) {
			beta = 0;
			Agregar(new Gamma());
		}

		Entidad** aux = new Entidad * [cant + 1];
		for (int i = 0; i < cant; i++)
			aux[i] = arreglo[i];
		aux[cant] = nuevo;
		cant++;
		arreglo = aux;
	}

	void Eliminar(Entidad* eliminado) {
		Entidad** aux = new Entidad * [cant - 1];

		int i;
		for (i = 0; arreglo[i] != eliminado; i++)
			aux[i] = arreglo[i];

		for (int j = i; j < cant - 1; j++)
			aux[j] = arreglo[j + 1];
		delete eliminado;
		cant--;
		arreglo = aux;
	}

	void Borrar() {
		for (int i = 0; i < cant; i++)
			arreglo[i]->Borrar();
	}

	void Mover() {
		for (int i = 0; i < cant; i++)
			if (arreglo[i]->GetY() + arreglo[i]->GetAlto() + 1 == ALTO) {
				arreglo[i]->Borrar();
				Eliminar(arreglo[i]);
			}

		for (int i = 0; i < cant; i++)
			arreglo[i]->Mover();
	}

	void Mostrar() {
		for (int i = 0; i < cant; i++) {
			switch (arreglo[i]->GetID()) {
			case 1: ((Alfa*)arreglo[i])->Mostrar();  break;
			case 2: ((Beta*)arreglo[i])->Mostrar();  break;
			case 3: ((Gamma*)arreglo[i])->Mostrar();  break;
			}
		}
	}

	int GetCantidad() {
		return cant;
	}
};
