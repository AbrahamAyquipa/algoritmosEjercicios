#include<iostream>
#include <string>
using namespace std;

string continentes[5] = { "America del Norte","America del Sur","Asia","Europa","Africa" };
string nombreH[5]= { "Marriot","Westin","Perkin","BigHouse","LandingWay" };
string tipoH[4]= { "Bussines","Airport","Suite","Resort" };

class Hotel {
protected:
	string nombre;
	string localizacion;
	string tipo;
	int estrellas;
	int numeroH;
public:
	Hotel() {
		nombre = nombreH[rand() % 5];
		localizacion = continentes[rand() % 5];
		tipo = tipoH[rand() % 4];
		estrellas = rand() % 5 + 1;
		numeroH = 20 + rand() % 81;
	}

	~Hotel() {}

	string getNombre() { return nombre; }
	string getLocalizacion() { return localizacion; }
	string getTipo() { return tipo; }
	int getEstrellas() { return estrellas; }
	int getNumeroH() { return numeroH; }

	void getInfoHotel() {
		cout << "Nombre: " << nombre << endl;
		cout << "Localizacion: " << localizacion << endl;
		cout << "Tipo: " << tipo << endl;
		cout << "Estrellas: " << estrellas << endl;
		cout << "Numero de habitaciones: " << numeroH << endl;
	}
};
