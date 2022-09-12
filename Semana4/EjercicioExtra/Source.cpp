
#include "pch.h"
#include <iostream>
#include <conio.h>
#include "Controladora.h"

int main() {
	const int WIDTH = 60;
	const int HEIGHT = 20;

	System::Console::SetWindowSize(WIDTH, HEIGHT);
	System::Console::CursorVisible = false;

	Controladora* objControladora = new Controladora("DVD", WIDTH, HEIGHT);

	/*Instrucciones:
	* A = agregar
	* E = salir 
	* B = borrar
	*/

	while (true) {
		if (_kbhit()) {
			char t = _getch();
			t = toupper(t);

			if (t == 'E') break;

			objControladora->gestionarTecla(t);
			_flushall();
		}

		objControladora->runApp();
		_sleep(150);
	}

	delete objControladora;
	return 0;
}
