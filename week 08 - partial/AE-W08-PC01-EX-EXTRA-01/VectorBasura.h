#pragma once
#include "Basura.h"
#include <vector>

class VectorBasura {
private:
	vector<Basura*> basuras;
public:
	VectorBasura(int n, int width, int height) {
		while (n--) {
			this->agregarBasura(width, height);
			_sleep(100);
		}
	}

	~VectorBasura() {
		for (Basura* objBasura : this->basuras) {
			delete objBasura;
		}
		this->basuras.clear();
	}

	void agregarBasura(int width, int height) {
		Basura* objBasura = new Basura(width, height);

		System::Random numero_aleatorio;
		objBasura->setX(numero_aleatorio.Next(0, width - objBasura->getW()));
		objBasura->setY(numero_aleatorio.Next(0, height - objBasura->getH()));

		this->basuras.push_back(objBasura);
	}

	void gestionBasura(int width, int height) {
		for (Basura* objBasura : this->basuras) {
			objBasura->borrar();
			objBasura->mover();
			objBasura->imprimir();
		}
		this->eliminarBasura();
	}

	void eliminarBasura() {
		for (int i = 0; i < this->basuras.size(); ++i) {
			if (this->basuras.at(i)->getActivo()) continue;
			this->basuras.at(i)->borrar();
			this->basuras.erase(this->basuras.begin() + i);
			break;
		}
	}

	vector <Basura*>& getBasura() {
		return this->basuras;
	}
};
