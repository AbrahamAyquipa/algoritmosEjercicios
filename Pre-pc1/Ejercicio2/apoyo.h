#pragma once
#include <iostream>
using namespace std;

class Apoyo {
private:
	int codigo;
	int hospedaje;
	bool pasaje_vuelo_avion;
	char estado_becario;
public:
	Apoyo(int codigo, int hospedaje, bool pasaje_vuelo_avion, char estado_becario);
	~Apoyo();

	int getCodigo();
	int getHospedaje();
	bool getPasajeVueloAvion();
	char getEstadoBecario();

	void setCodigo(int codigo);
	void setHospedaje(int hospedaje);
	void setPasajeVueloAvion(bool pasaje_vuelo_avion);
	void setEstadoBecario(char estado_becario);

	void toString();
};

Apoyo::Apoyo(int codigo, int hospedaje, bool pasaje_vuelo_avion, char estado_bancario) {
	this->codigo = codigo;
	this->hospedaje = hospedaje;
	this->pasaje_vuelo_avion = pasaje_vuelo_avion;
	this->estado_becario = estado_bancario;
}

Apoyo::~Apoyo() {}

int Apoyo::getCodigo() { return this->codigo; }
int Apoyo::getHospedaje() { return this->hospedaje; }
bool Apoyo::getPasajeVueloAvion() { return this->pasaje_vuelo_avion; }
char Apoyo::getEstadoBecario() { return this->estado_becario; }

void Apoyo::setCodigo(int codigo) { this->codigo = codigo; }
void Apoyo::setHospedaje(int hospedaje) { this->hospedaje = hospedaje; }
void Apoyo::setPasajeVueloAvion(bool pasaje_vuelo_avion) { this->pasaje_vuelo_avion = pasaje_vuelo_avion; }
void Apoyo::setEstadoBecario(char estado_becario) { this->estado_becario = estado_becario; }

void Apoyo::toString() {
	cout << this->codigo << "\t" << this->hospedaje << "\t" << this->pasaje_vuelo_avion << "\t" << this->estado_becario << "\n";
}
