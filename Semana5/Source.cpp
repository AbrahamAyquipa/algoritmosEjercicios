#include "ArregloEntidad.h"

int main()
{
	Console::SetWindowSize(ANCHO, ALTO);
	Console::CursorVisible = false;
	ArregloEntidad* obj = new ArregloEntidad();

	Console::SetCursorPosition(ANCHO / 2 - 5, ALTO / 2);
	cout << "comienza la invasion";
	getch();
	system("cls");

	while (true)
	{
		if (_kbhit())
		{
			char tecla = toupper(_getch());
			if (tecla == 'A')
				obj->Agregar(new Alfa());
		}

		obj->Borrar();
		obj->Mover();
		obj->Mostrar();

		if (obj->GetCantidad() >= 20)
			break;
		
		_sleep(200);
	}
	system("cls");
	Console::SetCursorPosition(ANCHO / 2 - 11, ALTO / 2);
	cout << "Hemos sido invadidos...";
	_sleep(8000);
	return 0;
}
