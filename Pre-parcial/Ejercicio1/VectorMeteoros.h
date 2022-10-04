#pragma once
#include "Meteoro.h"
#include <vector>

class VectorMeteoros {
private:
	vector<Meteotoro*> meteoros;
public:
	VectorMeteoros(int n, int width, int height) {
		while (n--) {
			this->agregarMeteoros(width, height);
			_sleep(100);
		}
	}

	~VectorMeteoros() {
		for (Meteotoro* estrellas : this->meteoros) {
			delete estrellas;
		}
		this->meteoros.clear();
	}

	void agregarMeteoros(int width, int height) {
		Meteotoro* objMeteoros = new Meteotoro(width, height);

		System::Random numero_aleatorio;
		objMeteoros->setX(numero_aleatorio.Next(0, width - objMeteoros->getW()));
		objMeteoros->setY(numero_aleatorio.Next(0, height - objMeteoros->getH()));

		this->meteoros.push_back(objMeteoros);
	}

	void gestionMeteoros(int width, int height) {
		for (Meteotoro* meteoros : this->meteoros) {
			meteoros->borrar();
			meteoros->mover();
			meteoros->imprimir();
		}
		this->eliminarMeteoros();
	}

	void eliminarMeteoros() {
		for (int i = 0; i < this->meteoros.size(); ++i) {
			if (this->meteoros.at(i)->getActivo()) continue;
			this->meteoros.at(i)->borrar();
			this->meteoros.erase(this->meteoros.begin() + i);
			break;
		}
	}

	vector <Meteotoro*>& getMeteoros() {
		return this->meteoros;
	}
};
