#include "pch.h"
#include "Rectangulo.h"
#include "Romboide.h"
#include "Triangulo.h"

int main() {
	double base = 5.2;
	double altura = 9.6;
	double lado1 = 2;
	double lado2 = 6;
	double lado3 = 56;

	Rectangulo* objRectangulo = new Rectangulo(base, altura, lado1, lado2, lado3);
	Romboide* objRomboide = new Romboide(base, altura, lado1, lado2, lado3);
	Triangulo* objTriangulo = new Triangulo(base, altura, lado1, lado2, lado3);

	cout << "Calular el area de un rectangulo: ";
	objRectangulo->calcularArea();
	cout << endl;
	cout << "Calular el perimetro de un rectangulo: ";
	objRectangulo->calcularPerimetro();
	cout << endl << endl;

	cout << "Calular el area de un romboide: ";
	objRomboide->calcularArea();
	cout << endl;
	cout << "Calular el perimetro de un romboide: ";
	objRomboide->calcularPerimetro();
	cout << endl << endl;

	cout << "Calular el area de un triangulo: ";
	objTriangulo->calcularArea();
	cout << endl;
	cout << "Calular el perimetro de un triangulo: ";
	objTriangulo->calcularPerimetro();
	cout << endl;
	return 0;
}
