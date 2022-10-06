#include "pch.h"
#include "Controladora.h"
#include <conio.h>

int main() {
	const int WIDTH = 60;
	const int HEIGHT = 40;

	const int CANTIDAD_ESTRELLAS = 5;
	const int CANTIDAD_METEOROS = 6;
	const int CANTIDAD_BASURAS = 4;
	const int CANTIDAD_ALIENS = 3;

	const std::string MENSAJE_VICTORIA = "FELICIDADES, GANASTE!!!";
	char tecla;
	bool letrero = true;

	System::Console::SetWindowSize(WIDTH, HEIGHT);
	System::Console::CursorVisible = false;

	Controladora* juego = new Controladora(WIDTH, HEIGHT, CANTIDAD_ESTRELLAS, CANTIDAD_METEOROS, CANTIDAD_BASURAS, CANTIDAD_ALIENS);

	while (!(juego->gameOverCase1() || juego->gameOverCase2())) {
		if (_kbhit()) {
			tecla = _getch();
			juego->gestionTecla(toupper(tecla));
			_flushall();
		}
		juego->runGame();
		_sleep(150);
	}
	system("cls");
	while (true) {
		if (_kbhit()) break;
		System::Console::ForegroundColor = (System::ConsoleColor)(letrero ? 14 : 6);
		System::Console::SetCursorPosition((WIDTH - MENSAJE_VICTORIA.length()) / 2, HEIGHT / 2);
		std::cout << MENSAJE_VICTORIA;
		letrero = !letrero;
		_sleep(250);
	}
	delete juego;
	return 0;
}

/*
#include "pch.h"
#include "Monigote.h"
#include <conio.h>

int main() {
	int const WIDTH = 60;
	int const HEIGHT = 20;

	System::Console::SetWindowSize(WIDTH, HEIGHT);
	System::Console::CursorVisible = false;

	char tecla;

	Monigote* objMonigote = new Monigote(WIDTH, HEIGHT);

	while (true) {
		if (_kbhit()) {

			tecla = _getch();
			objMonigote->cambiarDireccion(toupper(tecla));

			_flushall();
		}
		objMonigote->borrar();
		objMonigote->mover();
		objMonigote->imprimir();

		_sleep(150);
	}
	system("pause>0");
	return 0;
}*/
