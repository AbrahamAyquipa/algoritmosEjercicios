#include "pch.h"
#include "Controlador.h"

int main() {
    Console::SetWindowSize(120, 30);
    Console::CursorVisible = false;
    Controlador* controlador = new Controlador();
    int tecla;

    while (true) {
        controlador->borrarTodo();
        controlador->colisiones();
        controlador->obtenerGanador();

        if (_kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);
            controlador->get_nave()->posicionar(tecla);
        }
        controlador->posicionarTodo();
        controlador->dibujarTodo();
        _sleep(100);
    }
}
