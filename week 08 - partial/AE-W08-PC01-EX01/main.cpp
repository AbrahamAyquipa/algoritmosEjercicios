#include "pch.h"
#include "arrProducto.h"

void menu() {
	cout << "::::::::::::::::::::MENU::::::::::::::::::::\n";
	cout << "1.- Agregar nuevo Producto\n";
	cout << "2.- Listado de Productos\n";
	cout << "3.- Eliminar registro Producto\n";
	cout << "4.- Reporte por Marca\n";
	cout << "5.- Reporte stock mayor a 10\n";
	cout << "6.- Modificar Producto\n";
	cout << "7.- Salir\n";
}

int main() {
	string nombre;
	string marca;
	string modelo;
	int stock;
	string color;
	double precio;

	Producto* objProducto = nullptr;
	ArrProducto* objArrProducto = new ArrProducto();

	int opcion, posicion;
	while (true) {
		do {
			menu();
			cout << "Ingresar opcion: "; cin >> opcion;
		} while (opcion < 1 || opcion > 6);

		if (opcion == 7) {
			system("cls");
			break;
		}
		system("cls");

		switch (opcion) {
		case 1:
			cout << "AGREGAR NUEVO PRODUCTO\n";
			cout << "Ingresar el nombre: "; cin >> nombre;
			cout << "Ingresar la marca: "; cin >> marca;
			cout << "Ingresar modelo: "; cin >> modelo;
			cout << "Ingresar el stock: "; cin >> stock;
			cout << "Ingresar el color: "; cin >> color;
			cout << "Ingresar el precio: "; cin >> precio;

			objArrProducto->agregarProductos(new Producto(nombre, marca, modelo, stock, color, precio));
			break;
		case 2:
			cout << "INGRESAR LISTA DE PRODUCTOS\n";
			objArrProducto->listaProductos();
			break;
		case 3:
			if (objArrProducto->getNumeroArreglo() < 1) break;
			cout << "ELIMINAR REGISTRO PRODUCTO\n";
			do {
				cout << "Posicion del 1 en adelante: "; cin >> posicion;
				--posicion;
			} while (posicion < 0 || posicion >= objArrProducto->getNumeroArreglo());

			objArrProducto->eliminarProducto(posicion);
			break;
		case 4:
			cout << "REPORTE POR MARCA:\n";
			cout << "Ingresar la marca: "; cin >> marca;
			objArrProducto->reportePorMarca(marca);
			break;
		case 5:
			cout << "REPORTE STOCK MAYOR A 10\n";
			objArrProducto->reporteStock();
			break;
		case 6:
			if (objArrProducto->getNumeroArreglo() < 1) break;
			cout << "MODIFICAR UN CONTACTO\n";
			do {
				cout << "Posicion del 1 en adelante: "; cin >> posicion;
				--posicion;
			} while (posicion < 0 || posicion >= objArrProducto->getNumeroArreglo());

			objProducto = objArrProducto->getPorductoSegunPosicion(posicion);

			cout << "AGREGAR NUEVO PRODUCTO\n";
			cout << "Ingresar el nombre: "; cin >> nombre;
			cout << "Ingresar la marca: "; cin >> marca;
			cout << "Ingresar modelo: "; cin >> modelo;
			cout << "Ingresar el stock: "; cin >> stock;
			cout << "Ingresar el color: "; cin >> color;
			cout << "Ingresar el precio: "; cin >> precio;

			objProducto->setNombre(nombre);
			objProducto->setMarca(marca);
			objProducto->setModelo(modelo);
			objProducto->setStock(stock);
			objProducto->setColor(color);
			objProducto->setPrecio(precio);
			objProducto = nullptr;
			break;
		}
		system("pause>0");
		system("cls");
	}
	delete objArrProducto;
	return 0;
}
