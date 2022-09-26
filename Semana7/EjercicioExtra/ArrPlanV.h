#pragma once
#include <vector>
#include "PlanVacaciones.h"
class ArrPlanV {
private:
	vector< PlanVacaciones*> arr; //PlanVacaciones **arr;
public:
	ArrPlanV() {}

	~ArrPlanV() {}

	void agregarPlanV() {
		PlanVacaciones* obj = new PlanVacaciones();
		arr.push_back(obj); // push_back: agrega un objeto al final del vector
	}

	void borrarUltimoPlanV() {
		arr.pop_back(); // pop_back elimina el ultimo objeto de un vector
	}

	//eliminar un plan de vacaciones en posicion
	void eliminarPos(int pos) {
		//arr.erase(arr.begin() + pos);
		vector<PlanVacaciones*>::iterator it = arr.begin();
		//i vs it -> uno obtiene la pos y otro obtiene la posicion + objeto
		advance(it, pos);
		//it=(index,obj)
		arr.erase(it);
	}

	//-	Mostrar la lista de vacaciones en un intervalo de fecha
	void reporte1(int a1, int a2) {
		if (a1 <= a2) {
			for (int i = 0; i < arr.size(); i++) {
				if (arr[i]->getAnio() >= a1 && arr[i]->getAnio() <= a2) {
					arr[i]->getInfoPlanV();
				}
				cout << "\n";
			}
		}
		else
			cout << "El anio " << a1 << " Debe ser menor al " << a2 << endl;
	}

	//-	Mostrar la lista de vacaciones que tiene el mismo Hotel
	void reporte2(string nombre) {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i]->getNombre() == nombre) {
					cout << "\n";
					arr[i]->getInfoPlanV();
			}
		}
	}

	//-	Los boletos que tiene cada Plan de Vacación
	void reporte3() {
		for (int i = 0; i < arr.size(); i++) {
			cout << "\n";
			arr[i]->getInfoBoleto();
		}
	}

	void reporte31() {
		for (PlanVacaciones* p : arr) {
			cout << "\n";
			p->getInfoBoleto();
		}
	}
};
