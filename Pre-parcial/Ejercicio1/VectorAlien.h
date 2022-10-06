#pragma once
#include "Alien.h"
#include <vector>

class VectorAlien {
private:
	vector<Alien*> aliens;
public:
	VectorAlien(int n, int width, int height) {
		while (n--) {
			this->agregarAlien(width, height);
			_sleep(100);
		}
	}

	~VectorAlien() {
		for (Alien* objAliens : this->aliens) {
			delete objAliens;
		}
		this->aliens.clear();
	}

	void agregarAlien(int width, int height) {
		Alien* objAliens = new Alien(width, height);

		System::Random numero_aleatorio;
		objAliens->setX(numero_aleatorio.Next(0, width - objAliens->getW()));
		objAliens->setY(numero_aleatorio.Next(0, height - objAliens->getH()));

		this->aliens.push_back(objAliens);
	}

	void gestionAlien(int width, int height) {
		for (Alien* objAliens : this->aliens) {
			objAliens->borrar();
			objAliens->mover();
			objAliens->imprimir();
		}
		this->eliminarAlien();
	}

	void eliminarAlien() {
		for (int i = 0; i < this->aliens.size(); ++i) {
			if (this->aliens.at(i)->getActivo()) continue;
			this->aliens.at(i)->borrar();
			this->aliens.erase(this->aliens.begin() + i);
			break;
		}
	}

	vector <Alien*>& getBasura() {
		return this->aliens;
	}
};
