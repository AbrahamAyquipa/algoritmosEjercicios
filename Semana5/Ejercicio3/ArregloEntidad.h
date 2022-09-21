#pragma once
#include "Entidad.h"
#include "Avion1.h"
#include "Avion2.h"
#include "Avion3.h"
#include "Avion4.h"
#include "Avion5.h"
#include "Avion6.h"
#include "Avion7.h"
#include "Avion8.h"
#include "Avion9.h"

class ArregloEntidad {
private:
	int cant;
	Entidad** arreglo;
public:
	ArregloEntidad() {
		cant = 0;
	}
	~ArregloEntidad()
	{
		for (int i = 0; i < cant; i++)
			delete arreglo[i];
		delete[] arreglo;
	}

	void Agregar(Entidad* nuevo)
	{	
		Entidad** aux = new Entidad * [cant + 1];
		
		for (int i = 0; i < cant; i++)
			aux[i] = arreglo[i];
		
		aux[cant] = nuevo;
		
		cant++;
		arreglo = aux;
	}
	void Eliminar(Entidad* eliminado)
	{
		Entidad** aux = new Entidad * [cant - 1];
		
		int i;
		for (i = 0; arreglo[i] != eliminado; i++)
			aux[i] = arreglo[i];

		for (int j = i; j < cant - 1; j++)
			aux[j] = arreglo[j + 1];

		delete eliminado;
		cant--;
		arreglo = aux;
	}
	void Eliminar(int pos)
	{
		if (pos < cant)
		{
			arreglo[pos]->Borrar();
			Eliminar(arreglo[pos]);
		}
	}

	void Borrar()
	{
		for (int i = 0; i < cant; i++)
			arreglo[i]->Borrar();
	}
	void Mover()
	{
		for (int i = 0; i < cant; i++)
			arreglo[i]->Mover();
	}
	void Mostrar()
	{
		for (int i = 0; i < cant; i++)
		{
			arreglo[i]->Mostrar();
			/*switch (arreglo[i]->GetID())
			{
			case 1: ((Avion1*)(arreglo[i]))->Mostrar(); break;
			case 2: ((Avion2*)(arreglo[i]))->Mostrar(); break;
			case 3: ((Avion3*)(arreglo[i]))->Mostrar(); break;
			case 4: ((Avion4*)(arreglo[i]))->Mostrar(); break;
			case 5: ((Avion5*)(arreglo[i]))->Mostrar(); break;
			case 6: ((Avion6*)(arreglo[i]))->Mostrar(); break;
			case 7: ((Avion7*)(arreglo[i]))->Mostrar(); break;
			case 8: ((Avion8*)(arreglo[i]))->Mostrar(); break;
			case 9: ((Avion9*)(arreglo[i]))->Mostrar(); break;
			}*/
		}
	}
};
