#include "pch.h"
#include "Carrera.h"

int main()
{
    Console::SetWindowSize(80, 40);
    Console::CursorVisible = false;
    
    //variable
    Carrera* objetoCarrera;
    //instsancia el objeto
    objetoCarrera = new Carrera();

    objetoCarrera->inicia_carrera();


    system("pause>0");
    return 0;
}
