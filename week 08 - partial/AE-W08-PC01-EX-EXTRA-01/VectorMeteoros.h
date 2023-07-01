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
		for (Meteotoro* objMeteoro: this->meteoros) {
			delete objMeteoro;
		}
		this->meteoros.clear();
	}

	void agregarMeteoros(int width, int height) {
		Meteotoro* objMeteoro = new Meteotoro(width, height);

		System::Random numero_aleatorio;
		objMeteoro->setX(numero_aleatorio.Next(0, width - objMeteoro->getW()));
		objMeteoro->setY(numero_aleatorio.Next(0, height - objMeteoro->getH()));

		this->meteoros.push_back(objMeteoro);
	}

	void gestionMeteoros(int width, int height) {
		for (Meteotoro* objMeteoro : this->meteoros) {
			objMeteoro->borrar();
			objMeteoro->mover();
			objMeteoro->imprimir();
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
