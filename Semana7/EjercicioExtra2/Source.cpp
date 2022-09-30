#include "pch.h"
#include "Rectangulo.h"
#include "Romboide.h"

int main() {
	double base = 5.2;
	double altura = 9.6;
	Rectangulo* objRectangulo = new Rectangulo();
	Romboide* objRomboide = new Romboide();
	cout << "Calular el area de un rectangulo: ";
	objRectangulo->calcularArea(base, altura);
	cout << endl;
	cout << "Calular el perimetro de un rectangulo: ";
	objRectangulo->calcularPerimetro(base, altura);
	cout << endl << endl;
	cout << "Calular el area de un romboide: ";
	objRomboide->calcularArea(base, altura);
	cout << endl;
	cout << "Calular el perimetro de un romboide: ";
	objRomboide->calcularPerimetro(base, altura);
	cout << endl << endl;
	return 0;
}
