#include "pch.h"
#include "arrPlatos.h"
#include <iostream>
using namespace std;

int menu() {
	int opcion;
	do {
		cout << "\t\tMENU PRINCIPAL\n";
		cout << "\t1. Registro de platos\n";
		cout << "\t2. Mostrar todos los platos\n";
		cout << "\t3. Modificar datos de un plato\n";
		cout << "\t4. Eliminar un plato\n";
		cout << "\t5. Reporte de platos picantes\n";
		cout << "\t6. Reporte de platos más caros (mayores a 100 soles)\n";
		cout << "\t7. Salir\n\n" << endl;
		cout << "\tOpcion: "; cin >> opcion;
	} while (!(opcion > 0 && opcion < 8));
	return opcion;
}

int main() {
	int posicion;

	string nombre;
	bool frioOCaliente;
	bool picante;
	float calorias;
	float precio;

	plato* objPlato = nullptr;
	arrPlato* objArrPlato = new arrPlato();

	while (true) {
		system("cls");
		int opcion = menu();
		if (opcion == 7) {
			system("cls");
			break;
		}
		system("cls");

		switch (opcion) {
		case 1:
			cout << "\t\tREGISTRO DEL PLATO\n\n";
			cout << "\tNombre: "; cin >> nombre;
			cout << "\tPlato frio(1) o caliente(0): "; cin >> frioOCaliente;
			cout << "\tPlato picante(1) o no picante(0) : "; cin >> picante;
			cout << "\tCantidad de calorias: "; cin >> calorias;
			cout << "\tPrecio del plato: "; cin >> precio;

			//Guardar el plato en la memoria
			objArrPlato->agregarPlato(new plato(nombre, frioOCaliente, picante, calorias, precio));

			cout << "\n\tRegistro exitoso...";
			break;
		case 2: objArrPlato->listaPlatos(); break;
		case 3:
			if (objArrPlato->getNumeroPlatos() == 0) break;

			cout << "\t\tModificar plato\n\n";
			do {
				cout << "\tPosicion: "; cin >> posicion;
			} while (posicion < 0 && posicion <= objArrPlato->getNumeroPlatos());

			objPlato = objArrPlato->getPlatosSegunPosicion(posicion);

			cout << "\t\REGISTRO DEL PLATO\n\n";
			cout << "\tNombre: "; cin >> nombre;
			cout << "\tPlato frio(1) o caliente(0): "; cin >> frioOCaliente;
			cout << "\tPlato picante(1) o no picante(0) : "; cin >> picante;
			cout << "\tCantidad de calorias: "; cin >> calorias;
			cout << "\tPrecio del plato: "; cin >> precio;

			objPlato->setNombre(nombre);
			objPlato->setFrioOCaliente(frioOCaliente);
			objPlato->setPicante(picante);
			objPlato->setCalorias(calorias);
			objPlato->setPrecio(precio);
			objPlato = nullptr;

			cout << "\n\tRegistro exitoso...";
			break;
		case 4:
			if (objArrPlato->getNumeroPlatos() == 0) break;

			cout << "\t\tEliminar un plato\n\n";
			do {
				cout << "\tPosicion: "; cin >> posicion;
			} while (posicion < 0 && posicion <= objArrPlato->getNumeroPlatos());

			objArrPlato->eliminarPlato(posicion);

			cout << "\n\tContacto eliminado correctamente...";
			break;
		case 5:
			cout << "\tREPORTE DE PLATOS PICANTES" << endl;
			objArrPlato->reportePicante();
			break;
		case 6:
			cout << "\tREPORTE DE PLATOS CAROS" << endl;;
			objArrPlato->reportemas100();
			break;
		}
		system("pause>0");
	}
	delete objArrPlato;
	system("pause>0");
	return 0;
}
