#include "pch.h"
#include "contactList.h"
#include <iostream>
using namespace std;

int menu() {
	int opcion;
	do {
		cout << "\t\tMenu:\n";
		cout << "\t1. Agregar contacto\n";
		cout << "\t2. Eliminar contacto\n";
		cout << "\t3. Modificar contacto\n";
		cout << "\t4. Lista de mis contactos\n";
		cout << "\t5. Salir\n\n";
		cout << "\tOpcion: "; cin >> opcion;
	} while (!(opcion > 0 && opcion < 6));
	return opcion;
}

int subMenuListaContactos() {
	int opcion;
	do {
		cout << "\t1. Todos los contactos\n";
		cout << "\t2. Solo varones\n";
		cout << "\t3. Los que cumplen anios en mayo\n";
		cout << "\t4. Quienes tienen Facebook y WhatsApp\n\n";
		cout << "\topcion: "; cin >> opcion;
	} while (!(opcion > 0 && opcion < 5));
	return opcion;
}

int main() {
	int posicion;

	string nombre;
	int numero_telefono;
	char sexo;
	string facultad;
	string fecha_nacimiento;
	string email;
	string red_social;

	contacto* objContacto = nullptr;
	arrContactos* objArrContactos = new arrContactos();

	while (true) {
		system("cls");
		int opcion = menu();
		if (opcion == 5) {
			system("cls");
			break;
		}
		system("cls");

		switch (opcion) {
		case 1:
			cout << "\t\tAgregar nuevo contacto\n\n";
			cout << "\tNombre: "; cin >> nombre;
			cout << "\tNumero de telefono: "; cin >> numero_telefono;
			do {
				cout << "\tSexo (F: femenino, M: masculino): "; cin >> sexo;
				sexo = toupper(sexo);
			} while (!(sexo == 'M' || sexo == 'F'));
			cout << "\tFacultad: "; cin >> facultad;
			cout << "\tFecha de nacimiento: "; cin >> fecha_nacimiento;
			cout << "\tEmail: "; cin >> email;
			cout << "\tSocial Network: "; cin >> red_social;

			objArrContactos->agregarContacto(new contacto(nombre, numero_telefono, sexo, facultad, fecha_nacimiento, email, red_social));

			cout << "\n\tRegistro exitoso...";
			break;
		case 2:
			if (objArrContactos->getNumeroContactos() == 0) break;

			cout << "\t\tEliminar un contacto\n\n";
			do {
				cout << "\tPosicion: "; cin >> posicion;
			} while (posicion < 0 && posicion <= objArrContactos->getNumeroContactos());

			objArrContactos->eliminarContacto(posicion);

			cout << "\n\tContacto eliminado correctamente...";
			break;
		case 3:
			if (objArrContactos->getNumeroContactos() == 0) break;
			cout << "\t\tModificar contacto\n\n";

			do {
				cout << "\tPosicion: "; cin >> posicion;
			} while (posicion < 0 && posicion <= objArrContactos->getNumeroContactos());

			objContacto = objArrContactos->getContactoSegunPosicion(posicion);

			cout << "\t\tAgregar nuevo contacto\n\n";
			cout << "\tNombre: "; cin >> nombre;
			cout << "\tNumero de telefono: "; cin >> numero_telefono;
			do {
				cout << "\tSexo (F: femenino, M: masculino): "; cin >> sexo;
				sexo = toupper(sexo);
			} while (!(sexo == 'M' || sexo == 'F'));
			cout << "\tFacultad: "; cin >> facultad;
			cout << "\tFecha de nacimiento: "; cin >> fecha_nacimiento;
			cout << "\tEmail: "; cin >> email;
			cout << "\tSocial Network: "; cin >> red_social;

			objContacto->setNombre(nombre);
			objContacto->setNumeroTelefono(numero_telefono);
			objContacto->setSexo(sexo);
			objContacto->setFacultad(facultad);
			objContacto->setFechaNacimiento(fecha_nacimiento);
			objContacto->setEmail(email);
			objContacto->setRedSocial(red_social);
			objContacto = nullptr;

			cout << "\n\tRegistro exitoso...";
			break;
		case 4:
			cout << "\t\tLista de contactos\n\n";
			int opcion = subMenuListaContactos();
			switch (opcion) {
			case 1: objArrContactos->listaContactos(); break;
			case 2: objArrContactos->listaContactosVarones(); break;
			case 3: objArrContactos->listaContactosCumpleañosMayo(); break;
			case 4: objArrContactos->listaContactosQueTienenFbYWhtsp();
			}
			break;
		}
		system("pause>0");
	}
	delete objArrContactos;
	system("pause>0");
	return 0;
}
