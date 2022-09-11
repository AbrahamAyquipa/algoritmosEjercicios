#include "pch.h"
#include "ArrCuadrados.h"

using namespace std;
using namespace System;

int main() {
    const int WIDTH = 60;
    const int HEIGHT = 20;

    Console::SetWindowSize(WIDTH, HEIGHT);
    System::Console::CursorVisible = false;

    Cuadrado* objCuadrado = nullptr;
    ArrCuadrados* objArrCuadrados = new ArrCuadrados;

    while (true) {

        if (objArrCuadrados->getNumeroCuadrados() > 0) objArrCuadrados->MostrarCuadrado();

        if (_kbhit()) {
            char tecla = getch();
            tecla = toupper(tecla);

            switch (tecla) {
            case 'A':
                objCuadrado = new Cuadrado();
                objArrCuadrados->AgregarCuadrado(objCuadrado);
                break;
            case 'E':
                if (objArrCuadrados->getNumeroCuadrados() > 0)  objArrCuadrados->EliminarCuadrado();  
                break;
            case 'C':
                objArrCuadrados->CambiarColor();
                break;
            }
        }
        _sleep(20);
    }
    system("pause>0");
    delete objCuadrado;
    delete objArrCuadrados;
    return 0;
}
