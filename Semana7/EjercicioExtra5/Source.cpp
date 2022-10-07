#include <ctime>
#include <conio.h>
#include "ArrSolicitudes.h"
#include <iostream>
using namespace std;
using namespace System;

short menu() {
	short opcion;
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << "\t\tTRACKER ROBOT";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "\n\t\tMENU\n";
	cout << "\t\t=================\n";
	cout << "\t\t[1] INGRESAR DATOS\n";
	cout << "\t\t[2] REPORTE TOTAL\n";
	cout << "\t\t[3] SALIR\n";
	do {
		cout << "\t\tElija una opcion del menu: "; cin >> opcion;
	} while (opcion > 3 || opcion < 1);
	return opcion;
}
int main() {
	short op;
	ArrSolicitudes* arr = new ArrSolicitudes();
	while (true) {
		system("cls");

		op = menu();
		if (op == 1) {
			char TRANSMISION, REPERCUSION, EFICACIA, MORTANDAD;
			bool transmision, repercusion, eficacia, mortandad;
			system("cls");
			Console::ForegroundColor = ConsoleColor::Yellow;
			cout << "\t\tTRACKER ROBOT";
			Console::ForegroundColor = ConsoleColor::White;
			cout << "\n\tResponda las siguientes preguntas\n";
			do {
				cout << "¿Se transmite con facilidad? [S]si [N]no :"; cin >> TRANSMISION;
			} while (TRANSMISION != 'S' && TRANSMISION != 's' && TRANSMISION != 'n' && TRANSMISION != 'N');
			TRANSMISION = toupper(TRANSMISION);
			if (TRANSMISION == 'S')transmision = true;
			else transmision = false;
			cout << endl;
			do {
				cout << "¿Repercusión con medicamentos monoclonales? [S]si[N]no :"; cin >> REPERCUSION;
			} while (REPERCUSION != 'S' && REPERCUSION != 's' && REPERCUSION != 'n' && REPERCUSION != 'N');
			REPERCUSION = toupper(REPERCUSION);
			if (REPERCUSION == 'S')repercusion = true;
			else repercusion = false;
			cout << endl;
			do {
				cout << "¿Disminuye la eficacia de los anticuerpos ? [S]si[N]no :"; cin >> EFICACIA;
			} while (EFICACIA != 'S' && EFICACIA != 's' && EFICACIA != 'n' && EFICACIA != 'N');
			EFICACIA = toupper(EFICACIA);
			if (EFICACIA == 'S')eficacia = true;
			else eficacia = false;
			cout << endl;
			do {
				cout << "¿Mayor riesgo de muerte ? [S]si[N]no :"; cin >> MORTANDAD;
			} while (MORTANDAD != 'S' && MORTANDAD != 's' && MORTANDAD != 'n' && MORTANDAD != 'N');
			MORTANDAD = toupper(MORTANDAD);
			if (MORTANDAD == 'S')mortandad = true;
			else mortandad = false;
			cout << endl;
			Solicitud* sol = new Solicitud(transmision, mortandad, repercusion, eficacia);
			cout << "\t\tSe ha identificado la variante " << sol->getVariante();
			cout << "\nPresione una tecla para volver al menu..." << endl;
			arr->agregarSolicitud(sol);
			_getch();
			system("cls");
			menu();
		}
		else if (op == 2) {
			system("cls");
			Console::ForegroundColor = ConsoleColor::Yellow;
			cout << "\t\tTRACKER ROBOT";
			cout << "\n\tREPORTE";
			arr->reporte();
			cout << "\nPresione una tecla para volver al menu..." << endl;
			_getch();
			system("cls");

			menu();
		}
		else {
			exit(0);
		}
	}
		return 0;
}
