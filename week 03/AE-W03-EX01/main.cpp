#include "pch.h"
#include "arrEncuestados.h"

void menu() {
	cout << "MENU\n";
	cout << "1. Generar\n";
	cout << "2. Mostrar\n";
	cout << "3. Eliminar\n"; 
}

int main() {
	srand(time(NULL));
	int opcion;
	
	arrEncuestados* objArrEncuestas = new arrEncuestados();

	while (true) { 

		system("cls");

		do {
			menu();
			cout << "Opcion: "; cin >> opcion;
		} while (!(opcion > 0 && opcion < 4));

		switch (opcion) {
		case 1:
			int aleatorio_dni, aletorio_tipo_leche;
			aleatorio_dni = (1000000 + rand() % 70000000);
			aletorio_tipo_leche = 1 + rand() % 4;

			objArrEncuestas->generarEncuesta(new encuesta (aleatorio_dni, aletorio_tipo_leche));

			cout << "Generado correctamente...\n";
			break;
		case 2: 
			cout << "LISTA:\n";
			objArrEncuestas->mostrarEncuesta();
			break;
		case 3:
			int posicion;
			do {
				cout << "Posicion(de 1 en adelante): "; cin >> posicion;
				--posicion;
			} while (posicion < 0 || posicion >= objArrEncuestas->getNumeroEncuestados());
			objArrEncuestas->eliminarEncuesta(posicion);
			break;
		}
		system("pause>0");
	}
	delete objArrEncuestas;
	return 0;
}
