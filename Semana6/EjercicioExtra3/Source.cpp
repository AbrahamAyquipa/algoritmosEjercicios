#include "pch.h"
// Matrices.cpp: archivo de proyecto principal.
#include <iostream>
#include <conio.h>
using namespace System;
using namespace std;

int main() {
  char cTecla;
  int y = 9, x = 8;
  
  Console::SetCursorPosition(x, y); cout << (char)219;
  Console::SetCursorPosition(x + 1, y + 1);
  cout << (char)64;
  while (cTecla != char(78)) //N {
    cTecla = getch();
    Console::SetCursorPosition(x , y ); cout << " ";
    Console::SetCursorPosition(x + 1, y + 1); cout << " ";
    //if (cTecla == 0) cTecla = getch();

    if (cTecla == char(65)) --x;// A - 75
    if (cTecla == char(68)) ++x;//D - 77
    if (cTecla == char(87)) --y;//W - 72
    if (cTecla == char(83)) ++y;//S - 80
    Console::SetCursorPosition(x , y );
    cout << (char)219;

     Console::SetCursorPosition(x + 1, y + 1);
    cout << (char)64;
  }
return 0;
}
