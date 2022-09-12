#pragma once
#include "ArrText.h"
//controladora de todos los objetos

class Controladora {
private:
	ArrTexto* textos;
	int width, height;
public:
	Controladora(std::string valor, int width, int height) {
		this->textos = new ArrTexto();
		this->width = width;
		this->height = height;
	}

	~Controladora() {
		delete this->textos;
	}

	void gestionarTecla(char t) {
		if (t == 'A') {
			this->textos->agregarTexto(new Texto("DVD", this->width, this->height));
		}
		else if (t == 'B') {
			this->textos->eliminarTexto();
		}
	}

	void runApp() {
		this->textos->mostrarTextos(this->width, this->height);
	}
};
