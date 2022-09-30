#pragma once
#include "Entidad.h"

//Nave es una clase derivada de la clase Entidad.


class Nave : public Entidad {
public:
	Nave(int px, float py, int pdx, int palto, int pancho) : Entidad(px, py, pdx, palto, pancho) {
		dy = 2;
	}
	~Nave() {}

	void set_y(float py) {
		y = py;
	}

	float get_x() {
		return x;
	}

	void set_x(int px) {
		x = px;
	}

	void borrar() {
		Console::SetCursorPosition(x, int(y)); cout << "        ";
		Console::SetCursorPosition(x, int(y) + 1); cout << "        ";
		Console::SetCursorPosition(x, int(y) + 2); cout << "        ";
		Console::SetCursorPosition(x, int(y) + 3); cout << "        ";
	}

	void posicionar(char tecla) {
		switch (tecla) {
		case 75:
			if (x > Console::WindowLeft + 2)
				x -= dx;
			break;
		case 80:
			if (y + alto < Console::WindowHeight)
				y += dy;
			break;
		case 77:
			if (x + ancho < Console::WindowWidth)
				x += dx;
			break;
		case 72:
			if (y > Console::WindowTop)
				y -= dy;
			break;
		}
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(x, int(y)); cout << " __     ";
		Console::SetCursorPosition(x, int(y) + 1); cout << " " << char(92) << " " << char(92) << "___ ";
		Console::SetCursorPosition(x, int(y) + 2); cout << "#[==___>";
		Console::SetCursorPosition(x, int(y) + 3); cout << " /_/    ";
	}
};
