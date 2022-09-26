#include "Date.h"
class Boleto {
protected:
	int codigo;
	double precio;
	Date date;
public:
	Boleto() {
		codigo = rand() % 999999;
		precio = rand() % 10000;
		date = Date();
	}
	~Boleto() {}
	int getDia() { return date.getD(); }
	int getMes() { return date.getM(); }
	int getAnio() { return date.getA(); }
	void getInfoBoleto() {
		cout << "Codigo: " << codigo << endl;
		cout << "Precio: " << precio << endl;
		cout << "Date: " << date.getFechaCompleta() << endl;
	}

};


