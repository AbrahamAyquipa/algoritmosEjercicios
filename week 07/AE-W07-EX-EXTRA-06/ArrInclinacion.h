#pragma once
#include "Inclinacion.h"
#include <iostream>
#include <vector>
using namespace std;

class ArrInclinaciones {
private:
	vector<Inclinacion*> arr;
	short dc = 0, ic = 0, c = 0, dl = 0, il = 0;
public:
	ArrInclinaciones() {}
	~ArrInclinaciones() {}
	void agregarInclinacion(Inclinacion* obj) {
		arr.push_back(obj); // push_back: agrega un objeto al final del vector
	}

	void reporte() {
		for (Inclinacion* i : arr) {
			switch (i->getID()) {
			case 1: dc++; break;
			case 2: ic++; break;
			case 3: c++; break;
			case 4: dl++; break;
			case 5: il++; break;
			}
		}
		cout << "\nDER CONSERVADORA\t" << dc << " casos";
		cout << "\nIZQ CONSERVADORA\t" << ic << " casos";
		cout << "\nCENTRO\t\t\t" << c << " casos";
		cout << "\nDER LIBERAL\t\t" << dl << " casos";
		cout << "\nIZQ LIBERAL\t\t" << il << " casos";
	}
};
