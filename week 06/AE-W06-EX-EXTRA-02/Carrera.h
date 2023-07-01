#pragma once
#include "Dynamic.h"
#include "Leger.h"
#include "conio.h"
class Carrera
{
private:
	Dynamic* objetoDynamic;
	Leger* objetoLeger;

public:
	Carrera();
	~Carrera();
	void inicia_carrera();
	short meta;
};
//IMPLEMENTACION
Carrera::Carrera()
{
	srand(time(NULL));
	//instancia los objetos que participan en la carrera
	objetoDynamic = new Dynamic(2, 2);
	objetoLeger = new Leger(2, 10);
	meta = 65;
}

Carrera::~Carrera()
{
	delete objetoDynamic;
	delete objetoLeger;
}

void Carrera::inicia_carrera()
{
	bool hay_ganador = false;
	short dynamic = rand() % 2 + 1;
	short leger = rand() % 2 + 3;
	short ranking[2] = { 0 }; // 0->Dynamic 1->Leger
	
	while (true)
	{
		objetoDynamic->borrar();
		objetoDynamic->mover();
		objetoDynamic->dibujar(dynamic);

		objetoLeger->borrar();
		objetoLeger->mover();
		objetoLeger->dibujar(leger);

		if (objetoDynamic->get_x() > meta)
		{
			Console::SetCursorPosition(30, 35); cout << "GANA DYNAMIC";
			hay_ganador = true;
			ranking[0]++;
			getch();
		}
		if (objetoLeger->get_x() > meta)
		{
			Console::SetCursorPosition(30, 35); cout << "GANA LEGER";
			hay_ganador = true;
			ranking[1]++;
			getch();
		}

		//Si hay ganador
		if (hay_ganador)
		{
			//reiniciar otra carrera
			delete objetoDynamic; objetoDynamic = nullptr;
			delete objetoLeger; objetoLeger = nullptr;	
			Console::Clear();
			//se crea nuevamente los objetos
			objetoDynamic = new Dynamic(2, 2);
			objetoLeger = new Leger(2, 10);
			hay_ganador = false;
			//selecciona los nuevos competidores
			dynamic = rand() % 2 + 1;
			leger = rand() % 2 + 3;
		}

		if (kbhit())//estamos en plena carrera
		{
			char tecla = getch();
			if (tecla == 27) break;
		}

		_sleep(100);
	}//fin while

	//REPORTE
	cout << "\nRANKING\n";
	cout << " DYNAMIC ha ganado : " << ranking[0] << " carreras " << endl;
	cout << " LEGER   ha ganado : " << ranking[1] << " carreras " << endl;

	 
	system("pause>0");
}
