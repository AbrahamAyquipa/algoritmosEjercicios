#pragma once
#include "Solicitud.h"
#include <iostream>
#include <vector>
using namespace std;

class ArrSolicitudes {
private:
	vector<Solicitud*> arr; //ArrSolicitudes **arr;
	short ru = 0, su = 0, jb = 0, eu = 0, pc = 0;
public:
	ArrSolicitudes() {}
	~ArrSolicitudes() {}
	void agregarSolicitud(Solicitud*obj) {
		arr.push_back(obj); // push_back: agrega un objeto al final del vector
	}
	
	void reporte() {
		for (Solicitud* s : arr){

			switch (s->getID()) {
			case 1: ru++; break;
			case 2: su++; break;
			case 3: jb++; break;
			case 4: eu++; break;
			case 5: pc++; break;
			}		
		}
		cout << "\nREINO UNIDO\t" << ru << " casos";
		cout << "\nSUDAFRICA\t" << su << " casos";
		cout << "\nJAPON - BRASIL\t" << jb << " casos";
		cout << "\nESTADOS UNIDOS \t" << eu << " casos";
		cout << "\nPERU CHILE\t" << pc << " casos";
	}
};
