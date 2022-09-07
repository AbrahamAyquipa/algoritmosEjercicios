#include "pch.h"
#include "ArrApoyo.h"

void menu() {
	cout << "::::::::::::::::::::MENU::::::::::::::::::::\n";
	cout << "1. Agregar registro de informacion de becario\n";
	cout << "2. Listar informacion\n";
	cout << "3. Eliminar registro\n";
	cout << "4. Reporte de becarios que se encuentran de vacaciones\n";
	cout << "5. Reporte de becarios que el monto de hospedaje es mayor a 1000 soles\n";
	cout << "6. Reporte de becarios que cuentan con pasaje de vuelo de avion\n";
	cout << "7. Reporte de búsqueda de un becario\n";
	cout << "8. Modificar datos\n";
	cout << "9. Salir\n";
}

int main() {
	int opcion, posicion;

	int codigo;
	int hospedaje;
	bool pasaje_vuelo_avion;
	char estado_becario;

	Apoyo* objApoyo = nullptr;
	ArrApoyo* objArrApoyo = new ArrApoyo();

	while (true) {
		do {
			menu();
			cout << "Ingresar la opcion: "; cin >> opcion;
		} while (opcion < 1 || opcion > 7);

		if (opcion == 9) {
			system("cls");
			break;
		}

		system("cls");

		switch (opcion) {
		case 1: 
			cout << "AGREGAR REGISTRO\n";
			cout << "Ingresar el codigo (4 digitos): "; cin >> codigo;
			cout << "Ingresar el hospedaje: "; cin >> hospedaje;
			cout << "Ingresar el pasaje de vuelo de avion: "; cin >> pasaje_vuelo_avion;
			cout << "Ingresar estado bancario: "; cin >> estado_becario;

			objArrApoyo->agregarRegistro(new Apoyo(codigo, hospedaje, pasaje_vuelo_avion, estado_becario));
			break;
		case 2:
			cout << "LISTA DE REGISTROS:\n";
			objArrApoyo->listaApoyo();
			break;
		case 3:
			if (objArrApoyo->getNumeroApoyo() == 0) break;
			cout << "ELIMINAR REGISTRO\n";
			do{
				cout << "Ingresar posicion(mayor a 1): "; cin >> posicion;
				--posicion;
			} while (posicion < 0 || posicion >= objArrApoyo->getNumeroApoyo());

			objArrApoyo->eliminarRegistro(posicion);
			break;
		case 4:
			cout << "REPORTE DE BECARIOS EN VACACIONES\n";
			objArrApoyo->reporteBecariosVacaciones();
			break;
		case 5:
			cout << "REPORTE DE BECARIOS EN EL QUE MONTO DE HOSPEDAJE ES MAYOR A 100 SOLES\n";
			objArrApoyo->reporteHospedajeMayor100();
			break;
		case 6:
			cout << "REPORTE DE BECARIOS QUE CUENTAN CON PASAJE DE VUELO DE AVION\n";
			objArrApoyo->reporteBecariosConPasajeAvion();
			break;
		case 7:
			cout << "REPORTE DE BUSQUEDA DE UN BECARIO\n";
			cout << "Ingresar el codigo (4 digitos): "; cin >> codigo;
			objArrApoyo->busquedaBecario(codigo);
		case 8:
			if (objArrApoyo->getNumeroApoyo() == 0) break;
			cout << "MODIFICAR DATOS\n";
			do {
				cout << "Ingresar posicion(mayor a 1): "; cin >> posicion;
				--posicion;
			} while (posicion < 0 || posicion >= objArrApoyo->getNumeroApoyo());

			objApoyo = objArrApoyo->getApoyoSegunPosicion(posicion);

			cout << "Ingresar el codigo (4 digitos): "; cin >> codigo;
			cout << "Ingresar el hospedaje: "; cin >> hospedaje;
			cout << "Ingresar el pasaje de vuelo de avion: "; cin >> pasaje_vuelo_avion;
			cout << "Ingresar estado bancario: "; cin >> estado_becario;

			objApoyo->setCodigo(codigo);
			objApoyo->setHospedaje(hospedaje);
			objApoyo->setPasajeVueloAvion(pasaje_vuelo_avion);
			objApoyo->setEstadoBecario(estado_becario);
			objApoyo = nullptr;
			break;
		}
		system("pause>0");
		system("cls");

	}
	delete objArrApoyo;
	return 0;
}
