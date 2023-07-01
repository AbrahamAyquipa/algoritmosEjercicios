#include "pch.h"
#include <iostream>
#include <conio.h>
#include "Controladora.h"

int main() {
	const int WIDTH = 80;
	const int HEIGHT = 20;

	System::Console::SetWindowSize(WIDTH, HEIGHT);
	System::Console::CursorVisible = false;

	int n;
	char tecla;

	do {
		std::cout << "Ingrese la cantidad de aviones (2 - 5): ";
		std::cin >> n;
	} while (n < 2 || n > 5);

	Controladora* app = new Controladora(n, WIDTH, HEIGHT);
	system("cls");

	while (true) {
		if (_kbhit()) {
			tecla = _getch();
			tecla = toupper(tecla);

			if (tecla == 'E') break;

			_flushall();
		}
		app->runApp();
		_sleep(150);
	}
	delete app;
	return 0;
}
