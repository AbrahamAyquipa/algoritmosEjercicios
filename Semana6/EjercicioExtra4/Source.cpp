// Matrices.cpp: archivo de proyecto principal.
#include "pch.h"
#include <iostream>
#include <conio.h>
using namespace System;
using namespace std;

  int mov[20][20] =
{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
  /*{1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1}*/

int desp = 5;
void dibuja();
int main()
{
char cTecla;
int y = 9, x = 8, yy, xx;
dibuja();
Console::SetCursorPosition(x + desp, y + desp);
cout << (char) 219;
Console::SetCursorPosition(x + desp, y + desp);
while(cTecla != char(27)) // != ESC
{
 cTecla = getch();
 yy = y;
 xx = x;
 Console::SetCursorPosition(x + desp, y + desp);
 cout << " ";
 if(cTecla == 0) cTecla = getch();
 if(cTecla == char(75)) --x;
 if(cTecla == char(77)) ++x;
 if(cTecla == char(72)) --y;
 if(cTecla == char(80)) ++y;
 if(mov[y][x] == 1)
 {
 y = yy;
 x = xx;
 }
 Console::SetCursorPosition(x + desp, y + desp);
 cout << (char) 219;
 Console::SetCursorPosition(x + desp, y + desp);
}
return 0;
  }
void dibuja()
{
for(int f = 0; f<20; ++f)
 for(int c=0; c<20; ++c)
 {
 Console::SetCursorPosition(c + desp, f + desp);
 Console::ForegroundColor = ConsoleColor::Cyan;
 if(mov[f][c] == 1) cout << (char) 219;
 else cout << (char) 32;
 }
}
