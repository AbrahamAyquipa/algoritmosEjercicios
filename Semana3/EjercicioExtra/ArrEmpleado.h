#pragma once
#include <vector>
#include "Empleado.h"

class ArrEmpleado {
private:
	//Employee** arreglo; // arreglo dinamico 
	vector<Empleado*> arreglo; // arreglo con vector
public:
	ArrEmpleado() {}
	~ArrEmpleado() {}

	void addEmployee(Empleado* obj) {
		arreglo.push_back(obj);
	}

	void ListAll() {
		for (int i = 0; i < arreglo.size(); i++) {
			arreglo[i]->printData();
		}
	}

	void employeesBornInApril() {
		for (int i = 0; i < arreglo.size(); i++) {
			if (arreglo[i]->getBirthMonth() == 4) {
				arreglo[i]->printData();
			}
		}
	}

	int  employeesmarch2017() {
		int cont = 0;
		for (int i = 0; i < arreglo.size(); i++) {
			if (arreglo[i]->getHiringMonth() == 3 &&arreglo[i]->getHiringYear() == 2017) {
				cont++;
			}
		}
		return cont;
	}
};
