#pragma once
#include "Estrella.h"
#include <vector>

class VectorEstrellas {
private:
	vector<Estrella*> estrellas;
public:
	VectorEstrellas(int n, int width, int height) {
		while (n--) {
			this->agregarEstrellas(width, height);
			_sleep(100);
		}
	}

	~VectorEstrellas() {
		for (Estrella* objEstrellas : this->estrellas) {
			delete objEstrellas;
		}
		this->estrellas.clear();
	}

	void agregarEstrellas(int width, int height) {
		Estrella* objEstrellas = new Estrella(width, height);

		System::Random numero_aleatorio;
		objEstrellas->setX(numero_aleatorio.Next(0, width - objEstrellas->getW()));
		objEstrellas->setY(numero_aleatorio.Next(0, height - objEstrellas->getH()));

		this->estrellas.push_back(objEstrellas);
	}

	void gestionEstrellas(int width, int height) {
		for (Estrella* estrellas : this->estrellas) {
			estrellas->imprimir();
		}
		this->eliminarEstrellas();
	}

	void eliminarEstrellas() {
		for (int i = 0; i < this->estrellas.size(); ++i) {
			if (this->estrellas.at(i)->getActivo()) continue;
			this->estrellas.at(i)->borrar();
			this->estrellas.erase(this->estrellas.begin() + i);
			break;
		}
	}

	vector <Estrella*>& getEstrellas() {
		return this->estrellas;
	}
};
