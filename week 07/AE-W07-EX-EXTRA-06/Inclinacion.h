#pragma once
#include <iostream>
using namespace std;

class Inclinacion {
protected:
	bool libreMercado, libreComercio, igualdad, mentalidadAbierta, sensibilidad, estadoConValores;
	string inclinacion;
	int ID;
public:
	Inclinacion() {}
	Inclinacion(bool libreMercado, bool libreComercio, bool igualdad, bool mentalidadAbierta, bool sensibilidad, bool estadoConValores) {
		this->libreMercado = libreMercado;
		this->libreComercio = libreComercio;
		this->igualdad = igualdad;
		this->sensibilidad = sensibilidad;
		this->mentalidadAbierta = mentalidadAbierta;
		this->estadoConValores = estadoConValores;

		if (!libreComercio && estadoConValores) {
			inclinacion = "DERECHA CONSERVADORA";
			ID = 1;
		}
		else if (!libreComercio && !libreMercado && !estadoConValores ||
			!libreComercio && !libreMercado || !libreMercado && !estadoConValores) {
			inclinacion = "IZQUIERDA CONSERVADORA";
			ID = 2;
		}
		//sensibilidad y mente abierta son caracteristicas unicas
		else if (mentalidadAbierta && libreMercado && libreComercio && sensibilidad ||
			libreComercio && libreMercado && sensibilidad ||
			libreComercio && sensibilidad ||
			libreMercado && sensibilidad ||
			sensibilidad && mentalidadAbierta ||
			libreMercado && mentalidadAbierta ||
			libreComercio && mentalidadAbierta) {
			inclinacion = "CENTRO";
			ID = 3;
		}
		else if (libreMercado && libreComercio && estadoConValores ||
			libreComercio && libreMercado ||
			libreComercio && estadoConValores ||
			libreMercado && estadoConValores) {
			inclinacion = "DERECHA LIBERAL";
			ID = 4;
		}
		//como los casos se estan evaluando en orden, si solo hay una coincidencia
		//se esta evaluando la inclinacion sin chancar las posibilidades
		else if (libreMercado && libreComercio && igualdad ||
			libreMercado || igualdad) {
			inclinacion = "IZQUIERDA LIBERAL";
			ID = 5;
		}

		else if (mentalidadAbierta || sensibilidad) {
			inclinacion = "CENTRO";
			ID = 3;
		}
		else {
			//empates
			inclinacion = "No tengo suficiente informacion para realizar una prediccion!";
		}
	}
	~Inclinacion() {}
	string getInclinacion() { return inclinacion; }
	short getID() { return ID; }
};
