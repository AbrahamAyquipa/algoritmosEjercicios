#pragma once
#include <iostream>
using namespace std;

class Solicitud {
protected:
	bool transmision, mortandad, repercusion, eficacia;
	string variante;
	int ID;
public:
	Solicitud() {}
	Solicitud(bool transmision, bool mortandad, bool repercusion, bool eficacia){
		this->transmision = transmision;
		this->mortandad = mortandad;
		this->repercusion = repercusion;
		this->eficacia = eficacia;
		if (transmision && mortandad && !repercusion && !eficacia) {
			variante = "REINO UNIDO";
			ID = 1;
		}
		if (transmision && !mortandad && repercusion && eficacia) {
			variante = "SUDAFRICA";
			ID = 2;
		}
		if (!transmision && !mortandad && repercusion && eficacia) {
			variante = "JAPON-BRASIL";
			ID = 3;
		}
		if (transmision && !mortandad && !repercusion && eficacia) {
			variante = "ESTADOS UNIDOS";
			ID = 4;
		}
		if (transmision && !mortandad && !repercusion && !eficacia) {
			variante = "PERU-CHILE";
			ID = 5;
		}
		else {
			variante = "\n\tTu descripcion no coincide con la de ninguna variante registrada!";
		}
	}
	~Solicitud() {}
	bool getTransmision() { return transmision; }
	bool getMortandad() { return mortandad; }
	bool getRepercusion() { return repercusion; }
	bool getEficacia() { return eficacia; }
	string getVariante() { return variante; }
	short getID() { return ID; }
};
