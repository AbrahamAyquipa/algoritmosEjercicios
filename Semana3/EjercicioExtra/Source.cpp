#include"pch.h"
#include "ArrEmpleado.h"
#include<iostream>
using namespace System;

void menu() {
	cout << "1. Agregar Empleado" << endl;
	cout << "2. Empleados nacidos en Abril" << endl;
	cout << "3. Cantidad de empledos contratados en Marzo 2017" << endl;
	cout << "4. Lista de todos los empleados" << endl;
}


int main() {
	int option;
	string name, lastName;
	int day, month, year;
	Fecha b;
	Fecha h;

	Empleado* objEmpleado;
	ArrEmpleado* objArrEmpleado = new ArrEmpleado();

	while (1) {
		menu();
		cout << "input the option: "; cin >> option;
		switch (option)
		{
		case 1:
			cout << "Nombre del empleado: "; cin >> name;
			cout << "Apellido del empleado: "; cin >> lastName;
			do {
				cout << "Dia de Nacimiento: "; cin >> day;
				cout << "mes de Nacimiento: "; cin >> month;
				cout << "Anio de Nacimiento: "; cin >> year;
				b = Fecha(day, month, year);
			} while (!b.dateIsReal()); //b.dateIsReal()==false

			do {
				cout << "Dia de Contratacion: "; cin >> day;
				cout << "mes de Contratacion: "; cin >> month;
				cout << "Anio de Contratacion: "; cin >> year;
				h = Fecha(day, month, year);
			} while (!h.dateIsReal()); //b.dateIsReal()==false
			//creo a mi empleado
			objEmpleado = new Empleado(name, lastName, b, h);
			//agregamos un empleado a la clase arreglo
			objArrEmpleado->addEmployee(objEmpleado);
			cout << "Empleado agredado..." << endl;
			break;
		case 2:
			objArrEmpleado->employeesBornInApril(); break;
		case 3:
			cout << "Numero de empleados contrados en Marzo 2017: " << objArrEmpleado->employeesmarch2017() << endl; break;
		case 4:
			objArrEmpleado->ListAll(); break;

		}
		getch();
		Console::Clear();
	}
	getch();
	return 0;
}
