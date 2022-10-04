#pragma once
#include "Monigote.h"
#include "Estrella.h"
#include "VectorEstrellas.h"
#include "VectorMeteoros.h"

class Controladora {
private:
	Monigote* objMonigote;
	VectorEstrellas* objVectorEstrellas;

	VectorMeteoros* objVectorMeteoros;

	int cantidadCorazones;
	int width, height;
	int cantidadEstrellas;

	time_t tiempo;
public:
	Controladora(int width, int height, int cantidadEstrellas) {
		this->width = width;
		this->height = height;

		this->cantidadEstrellas = cantidadEstrellas;

		this->objMonigote = new Monigote(width, height);

		Random numero_aleatorio;
		this->objMonigote->setX(numero_aleatorio.Next(0, this->width - 1));
		this->objMonigote->setY(numero_aleatorio.Next(0, this->height - 2));
		
		this->objVectorEstrellas = new VectorEstrellas(this->cantidadEstrellas, width, height);

		this->objVectorMeteoros = new VectorMeteoros(this->cantidadEstrellas, width, height);

		tiempo = time(0);
	}

	~Controladora() { 
		delete this->objMonigote;
		delete this->objVectorEstrellas;
		delete this->objVectorMeteoros;
	}

	void gestionTecla(char tecla) {
		this->objMonigote->cambiarDireccion(tecla);
	}

	void gestionMonigote() {
		this->objMonigote->borrar();
		this->objMonigote->mover();
		this->objMonigote->imprimir();
	}

	void gestionColisionesEstrellas() {
		for (Estrella* estrellas : this->objVectorEstrellas->getEstrellas()) {
			if (estrellas->getRectangle().IntersectsWith(this->objMonigote->getRectangle())) {
				this->objMonigote->agregarEstrellasCapturadas();
				estrellas->setActivo(false);
				break;
			}
		}
	}

	void gestionarColisionesMeteoros() {
		for (Meteotoro* meteoros : this->objVectorMeteoros->getMeteoros()) {
			if (meteoros->getRectangle().IntersectsWith(this->objMonigote->getRectangle())) {
				system("cls");
				system("pause>0");
				exit(0);
			}
		}
	}

	void mostrarLetreroEstrellas() {
		System::Console::ForegroundColor = System::ConsoleColor::White;
		System::Console::SetCursorPosition(0, height - 1);
		cout << "Estrellas: ";
		int i;
		for (i = 0; i < objMonigote->getCantidadEstrellasAtrapados(); i++) {
			cout << char(42) << " ";
		}
		cout << i;
	}

	void mostrarLetreroTiempo() {
		System::Console::SetCursorPosition(0, height - 2); cout << "tiempo: " << clock() / 1000;
		if (clock() / 1000 == 60) {
			system("cls");
			system("pause>0");
			exit(0);
		} 
	}

	void runGame() {
		this->gestionMonigote();
		this->objVectorEstrellas->gestionEstrellas(width, height);
		this->objVectorMeteoros->gestionMeteoros(width, height);
		this->mostrarLetreroEstrellas();
		this->mostrarLetreroTiempo();
		this->gestionColisionesEstrellas();
		this->gestionarColisionesMeteoros();


	}
	bool isGameOverCase() {
		return this->objMonigote->getCantidadEstrellasAtrapados() == this->cantidadEstrellas;
	}
};
