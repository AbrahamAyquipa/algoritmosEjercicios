#include "pch.h"
#include "Rectangulo.h"
#include "Romboide.h"

int main() {
	const double base = 5;
	const double altura = 8;

	Rectangulo* objRectangulo = new Rectangulo(base, altura);
	Romboide* objRomboide = new Romboide(base, altura);

	cout << "VALORES: " << endl;
	cout << "base = 5" << endl;
	cout << "altura = 8" << endl;
	cout << endl;
	cout << "Area rectangulo: ";
	objRectangulo->calcularAreaRectangulo(base, altura);
	cout << endl;
	cout << "Perimetro rectangulo: ";
	objRectangulo->calcularPerimetroRectangulo(base, altura);
	cout << endl << endl;
	cout << "Area romboide: ";
	objRomboide->calcularAreaRomboide(base, altura);
	cout << endl;
	cout << "Perimetro romboide: ";
	objRomboide->calcularPerimetroRomboide(base, altura);
	cout << endl;
	return 0;
}
