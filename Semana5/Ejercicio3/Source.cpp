#include "ArregloEntidad.h"

int main() {
	srand(time(NULL));
	Console::SetWindowSize(ANCHO, ALTO);
	Console::CursorVisible = false;
	ArregloEntidad* obj = new ArregloEntidad();

	while (true) {
		if (_kbhit()) {
			char tecla = _getch();
			switch (tecla)
			{
			case '1': obj->Agregar(new Avion1()); break;
			case '2': obj->Agregar(new Avion2()); break;
			case '3': obj->Agregar(new Avion3()); break;
			case '4': obj->Agregar(new Avion4()); break;
			case '5': obj->Agregar(new Avion5()); break;
			case '6': obj->Agregar(new Avion6()); break;
			case '7': obj->Agregar(new Avion7()); break;
			case '8': obj->Agregar(new Avion8()); break;
			case '9': obj->Agregar(new Avion9()); break;
			case '0': obj->Eliminar(0); break;
			default: break;
			}
		}
		obj->Borrar();
		obj->Mover();
		obj->Mostrar();
		_sleep(200);
	}
}
