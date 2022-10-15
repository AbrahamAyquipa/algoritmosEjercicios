#include "ArrInclinaciones.h"
#include <conio.h>
#include <iostream>
using namespace std;
using namespace System;

//= Las preguntas se elegiran aleatoriamente desde su indice
string preguntas[6] = { "LIBRE MERCADO?","LIBRE COMERCIO?","IGUALDAD?", "MENTALIDAD ABIERTA?","SENSIBILIDAD?","ESTADO CON VALORES?" };

//short es lo mismo que un int, pero ocupa menos espacio de memoria
//lo uso porque estoy trabajando con valores pequeños (1,2,3...)

short menu() {
	short opcion;
	Console::ForegroundColor = ConsoleColor::Yellow;

	cout << "\t\tROBOT POLITICO";
	Console::ForegroundColor = ConsoleColor::White;
	cout << "\n\t\tMENU\n";
	cout << "\t\t=================\n";
	cout << "\t\t[1] INGRESAR DATOS\n";
	cout << "\t\t[2] REPORTE TOTAL\n";
	cout << "\t\t[3] SALIR\n";
	do {
		cout << "\tElija una opcion del menu: "; cin >> opcion;
	} while (opcion > 3 || opcion < 1);
	return opcion;
}
int main() {
	srand(time(NULL));
	short op;
	ArrInclinaciones* arr = new ArrInclinaciones();
	while (true) {

		system("cls");
		op = menu();

		if (op == 1) {
			bool libreMercado, libreComercio, igualdad, mentalidadAbierta, sensibilidad, estadoConValores;
			system("cls");
			Console::ForegroundColor = ConsoleColor::Yellow;
			cout << "\t\tROBOT POLITICO";
			Console::ForegroundColor = ConsoleColor::White;
			cout << "\n\tResponda las siguientes preguntas (S-Si, N-No, X-No se)\n";
			vector<int>preguntasSalieron;

			for (int i = 0; i < 4; i++) {
				bool flag = false;
				int random = rand() % 6;
				preguntasSalieron.push_back(random);
				int j = 0;
				if (i > 0) {
					for (j = 0; j < preguntasSalieron.size() - 1; j++) {
							if (random == preguntasSalieron[j]) {
								preguntasSalieron.pop_back();
								random = rand() % 6;
								preguntasSalieron.push_back(random);
							}
						}
				
				}
				
				char ans;
				cout << "\t" << preguntas[random] << endl;
				cout << "\t";
				cin >> ans;
				switch (random) {
				case 0:
					if (ans == 'S')libreMercado = true;
					else if (ans == 'N')libreMercado = false;
					else {
						libreMercado = NULL;
					}
					//si la respuesta es "No se", simplemente se ignora
					break;
				case 1:
					if (ans == 'S')libreComercio = true;
					else if (ans == 'N')libreComercio = false;
					else {
						libreComercio = NULL;
					}
					break;
				case 3:
					if (ans == 'S')igualdad = true;
					else if (ans == 'N')igualdad = false;
					else {
						igualdad = NULL;
					}
					break;

				case 4:
					if (ans == 'S')mentalidadAbierta = true;
					else if (ans == 'N')mentalidadAbierta = false;
					else {
						igualdad = NULL;
					}
					break;
				case 5:
					if (ans == 'S')sensibilidad = true;
					else if (ans == 'N')sensibilidad = false;
					else {
						sensibilidad = NULL;
					}
					break;
				case 6:
					if (ans == 'S')estadoConValores = true;
					else if (ans == 'N')estadoConValores = false;
					else {
						estadoConValores = NULL;
					}
					break;
				}
			}
			Inclinacion* inc = new Inclinacion(libreMercado, libreComercio, igualdad, mentalidadAbierta, sensibilidad, estadoConValores);
			cout << "\t\tSu inclinacion politica puede ser " << inc->getInclinacion();
			cout << "\n\n\tPresione una tecla para volver al menu..." << endl;
			_getch();
			system("cls");
			arr->agregarInclinacion(inc);
			menu();
		}
		else if (op == 2) {
			system("cls");
			Console::ForegroundColor = ConsoleColor::Yellow;
			cout << "\t\tROBOT POLITICO";
			cout << "\n\tREPORTE";
			arr->reporte();
			cout << "\n\n\tPresione una tecla para volver al menu..." << endl;
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
