#pragma once
#include "Fecha.h"

class Empleado {
private:
	string name;
	string lastName;
	Fecha birthDate;
	Fecha hiringDate;
public:
	Empleado(string n, string l, Fecha b, Fecha h) {
		name = n;
		lastName = l;
		birthDate = b;
		hiringDate = h;
	}
	int getBirthMonth() { return birthDate.getMonth(); }
	int getHiringMonth() { return hiringDate.getMonth(); }
	int getHiringYear() { return hiringDate.getYear(); }

	void printData() {
		cout << "Name: " << name << endl;
		cout << "Las Name: " << lastName << endl;
		cout << "BirthDate: " << birthDate.getDate() << endl;
		cout << "HiringDate: " << hiringDate.getDate() << endl;
	}
};
