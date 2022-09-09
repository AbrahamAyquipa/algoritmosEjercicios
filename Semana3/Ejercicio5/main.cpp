#include "pch.h"
#include <iostream>
#include "arrMotorizado.h"

void showMenu() {
	cout << "\t\tDELIVERY MAN MANAGER\n\n";
	cout << "\t1. Add a driver\n";
	cout << "\t2. Remove a driver\n";
	cout << "\t3. Show all drivers\n";
	cout << "\t4. Show drivers from Mapi\n";
	cout << "\t5. Show drivers from Glopo\n";
	cout << "\t6. Exit\n\n";
}

int main() {
	arrMotorizado* objArrMotorizados = new arrMotorizado();

	int opcion, posicion;

	string nombre, apellido, placa;
	float kilometraje;
	int empresa;

	while (true) {
		System::Console::ForegroundColor = System::ConsoleColor::White;

		do {
			system("cls");
			showMenu();
			cout << "\tOpcion: "; cin >> opcion;
		} while (opcion < 1 || opcion > 6);

		if (opcion == 6) break;

		system("cls");

		switch (opcion) {
		case 1:
			cout << "\t\tADD A DRIVER\n\n";
			cout << "\tName and lastname: "; cin >> nombre >> apellido;
			cout << "\tPlate: "; cin >> placa;

			do {
				cout << "\tMileage: "; cin >> kilometraje;
			} while (kilometraje < 0);

			do {
				cout << "\tSelect an enterprise (1: Mapi, 2: Glopo): "; cin >> empresa;
			} while (empresa < 1 || empresa > 2);

			objArrMotorizados->agregarMotorizado(new motorizado(nombre, apellido, placa, kilometraje, (empresa == 1 ? "Mapi" : "Glopo")));

			System::Console::ForegroundColor = System::ConsoleColor::Green;
			cout << "\n\tSuccessful registration.";
			break;
		case 2:
			if (objArrMotorizados->getNumeroMotorizados() == 0) break;
			cout << "\t\tREMOVE A DRIVER\n\n";

			do {
				cout << "\tEnter the driver position: ";
				cin >> posicion;
			} while (posicion < 0 || posicion >= objArrMotorizados->getNumeroMotorizados());

			objArrMotorizados->eliminarMotorizado(posicion);
			System::Console::ForegroundColor = System::ConsoleColor::Green;
			cout << "\n\tSuccessful operation.";
			break;
		case 3:
			cout << "\t\tSHOW ALL DRIVERS\n\n";
			objArrMotorizados->mostrarTodosMotorizados();
			break;
		case 4:
			cout << "\t\tSHOW DRIVERS FROM MAPI\n\n";
			objArrMotorizados->mostrarTodosMotorizadosMapi();
			break;
		case 5:
			cout << "\t\tSHOW DRIVERS FROM GLOPO\n\n";
			objArrMotorizados->mostrarTodosMotorizadosGlopo();
		}
		system("pause>0");
	}

	delete objArrMotorizados;
	return 0;
}
