#pragma once
#include "Alien.h"
#include "Proyectil.h"
#include "Nave.h"
#include <vector>

class Controlador {
private:
	Nave* nave;
	vector<Proyectil*> proyectiles;
	vector<Alien*> aliens;
	time_t tiempo;

public:
	Controlador() {
		nave = new Nave(2, 12, 3, 4, 8);
		tiempo = time(0);

		proyectiles.push_back(new Proyectil(27, 2, 1, 6, 6));
		proyectiles.push_back(new Proyectil(54, Console::WindowHeight - 7, 2, 6, 6));
		proyectiles.push_back(new Proyectil(81, 2, 1, 6, 6));
		proyectiles.push_back(new Proyectil(90, Console::WindowHeight - 7, 2, 6, 6));
		
		aliens.push_back(new Alien(37, 2, 1, 3, 11));
		aliens.push_back(new Alien(65, 2, 1, 3, 11));
	}
	~Controlador() {}

	void borrarTodo() {
		for (int i = 0; i < aliens.size(); i++) {
			aliens[i]->borrar();
		}
		for (int i = 0; i < proyectiles.size(); i++) {
			proyectiles[i]->borrar();
		}
		nave->borrar();
	}

	void posicionarTodo() {
		for (int i = 0; i < aliens.size(); i++) {
			aliens[i]->posicionar();
		}
		for (int i = 0; i < proyectiles.size(); i++) {
			if (int(proyectiles[i]->get_x() % 2) == 0) {
				proyectiles[i]->posicionar();
			}
			else
				proyectiles[i]->posicionar();
		}
	}

	void dibujarTodo() {
		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(109, 1);
		cout << "Tiempo: " << clock() / 1000;
		for (int i = 0; i < aliens.size(); i++) {
			aliens[i]->dibujar();
		}
		for (int i = 0; i < proyectiles.size(); i++) {
			if (int(proyectiles[i]->get_x() % 2) == 0) {
				proyectiles[i]->set_marca(1);
			}
			if (int(proyectiles[i]->get_x() % 2) != 0) {
				proyectiles[i]->set_marca(2);
			}
		}
		for (int i = 0; i < proyectiles.size(); i++) {
			if (proyectiles[i]->get_marca() == 1) {
				proyectiles[i]->dibujar_1();
			}
			if (proyectiles[i]->get_marca() == 2) {
				proyectiles[i]->dibujar_2();
			}
		}
		nave->dibujar();
	}

	void colisiones() {
		for (int i = 0; i < proyectiles.size(); i++) {
			if (nave->obtenerRectangulo().IntersectsWith(proyectiles[i]->obtenerRectangulo())) {
				nave->set_x(2);
				nave->set_y(12.0);
				eliminarVectores();
				Console::ForegroundColor = ConsoleColor::DarkRed;
				system("cls");
				Console::SetCursorPosition(38, 12);
				cout << "IMPACTO NAVE - PROYECTIL!!! - GAME OVER !!!";
				Console::SetCursorPosition(37, 14);
				cout << "Presiona una tecla para volver a intentarlo...";
				_getch();
				system("cls");
				agregarVectores();
				tiempo = time(0);
			}
		}
	}

	void obtenerGanador() {
		if (nave->get_x() + 8 >= Console::WindowWidth) {
			nave->set_x(2);
			nave->set_y(12.0);
			eliminarVectores();
			Console::ForegroundColor = ConsoleColor::Blue;
			system("cls");
			Console::SetCursorPosition(40, 12);
			cout << "FELICITACIONES!!! - LLEGO AL OBJETIVO !!!";
			Console::SetCursorPosition(41, 14);
			cout << "Presiona una tecla para volver a jugar";
			_getch();
			system("cls");
			agregarVectores();
			tiempo = time(0);
		}
	}

	void eliminarVectores() {
		aliens.clear();
		proyectiles.clear();
	}

	void agregarVectores() {
		proyectiles.push_back(new Proyectil(27, 2, 1, 6, 6));
		proyectiles.push_back(new Proyectil(54, Console::WindowHeight - 7, 1, 6, 6));
		proyectiles.push_back(new Proyectil(81, 2, 1, 6, 6));
		proyectiles.push_back(new Proyectil(90, Console::WindowHeight - 7, 1, 6, 6));
		
		aliens.push_back(new Alien(37, 2, 1, 3, 11));
		aliens.push_back(new Alien(65, 2, 1, 3, 11));
	}

	Nave* get_nave() {
		return nave;
	}
};
