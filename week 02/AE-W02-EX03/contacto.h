#pragma once
#include <iostream>
#include <string>
using namespace std;

class contacto {
private:
	string nombre;
	int numero_telefono;
	char sexo;
	string facultad;
	string fecha_nacimiento;
	string email;
	string red_social;
public:
	contacto(string nombre, int numero_telefono, char sexo, string facultad, string fecha_nacimiento, string email, string red_social);
	~contacto();

	//get
	char getSexo();
	string getRedSocial();
	string getFechaNacimiento();
	//set
	void setNombre(string nombre);
	void setNumeroTelefono(int numero_telefono);
	void setSexo(char sexo);
	void setFacultad(string facultad);
	void setFechaNacimiento(string fecha_nacimiento);
	void setEmail(string email);
	void setRedSocial(string red_social);

	void toString();

};

contacto::contacto(string nombre, int numero_telefono, char sexo, string facultad, string fecha_nacimiento, string email, string red_social) {
	this->nombre = nombre;
	this->numero_telefono = numero_telefono;
	this->sexo = sexo;
	this->facultad = facultad;
	this->fecha_nacimiento = fecha_nacimiento;
	this->email = email;
	this->red_social = red_social;
}

contacto::~contacto() {}

char contacto::getSexo() { return this->sexo; }
string contacto::getRedSocial() { return this->red_social; }
string contacto::getFechaNacimiento() { return this->fecha_nacimiento; }

void contacto::setNombre(string nombre) { this->nombre = nombre; }
void contacto::setNumeroTelefono(int numero_telefono) { this->numero_telefono = numero_telefono; }
void contacto::setSexo(char sexo) { this->sexo = sexo; }
void contacto::setFacultad(string facultad) { this->facultad = facultad; }
void contacto::setFechaNacimiento(string fecha_nacimiento) { this->fecha_nacimiento = fecha_nacimiento; }
void contacto::setEmail(string email) { this->email = email; }
void contacto::setRedSocial(string red_social) { this->red_social = red_social; }

void contacto::toString() {
	cout << "NOMBRE: " << this->nombre << " | TELEFONO: " << this->numero_telefono << " | SEXO: " << this->sexo << " | FACULTAD: " << this->facultad << " | F.N.: " << this->fecha_nacimiento << " | EMAIL: " << this->email << " | RED SOCIAL: " << this->red_social << '\n';
}
