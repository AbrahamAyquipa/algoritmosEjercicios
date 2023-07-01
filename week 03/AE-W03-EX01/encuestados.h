#pragma once
#include <iostream>
using namespace std;

class encuesta {
private:
	int dni;
	int tipo_leche;
public:
	encuesta(int dni, int tipo_leche);
	~encuesta();

	int getDni();
	int getTipoLeche();

	void setDni(int dni);
	void setTipoLeche(int tipo_leche);

	void toString();
};

encuesta::encuesta(int dni, int tipo_leche) {
	this->dni = dni;
	this->tipo_leche = tipo_leche;
}

encuesta::~encuesta() {};

int encuesta::getDni() { return this->dni; }
int encuesta::getTipoLeche() { return this->tipo_leche; }

void encuesta::setDni(int dni) { this->dni = dni; }
void encuesta::setTipoLeche(int tipo_leche) { this->tipo_leche = tipo_leche; }

void encuesta::toString() {
	cout << "REPORTE\n";
	cout << "DNI: " << this->dni << " | TIPO: " << this->tipo_leche << "\n";
}
