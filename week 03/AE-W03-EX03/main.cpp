#include "pch.h"
#include <iostream>
#include "controladora.h"

void mostrarMenu() {
	cout << "\t\tMENU\n\n";
	cout << "\t1. Registrar nuevo cliente\n";
	cout << "\t2. Registrar nuevo producto\n";
	cout << "\t3. Registrar nueva venta\n";
	cout << "\t4. Agregar stock al producto\n";
	cout << "\t5. Mostrar clientes\n";
	cout << "\t6. Mostrar productos\n";
	cout << "\t7. Mostrar ventas\n";
	cout << "\t8. Salir\n\n";
}

void registarNuevoCliente(controladora* obj) {
	string DNI, nombre;
	cout << "\t\tREGISTRAR NUEVO CLIENTE\n\n";
	cout << "\tDNI: "; cin >> DNI;
	cout << "\tProducto: "; cin >> nombre;

	if (obj->existeCliente(DNI)) {
		System::Console::ForegroundColor = System::ConsoleColor::Red;
		cout << "\n\tError: El cliente ya existe.";
		return;
	}

	obj->agregarCliente(DNI, nombre);

	System::Console::ForegroundColor = System::ConsoleColor::Green;
	cout << "\n\tRegistro exitoso.";
}

void registrarNuevoProducto(controladora* obj) {
	int codigo_producto;
	string nombre, tipo, marca;
	int stock;
	float precio;

	cout << "\t\tREGISTRAR UN NUEVO PRODUCTO\n\n";
	cout << "\tCodigo producto: "; cin >> codigo_producto;

	if (obj->existeProducto(codigo_producto)) {
		System::Console::ForegroundColor = System::ConsoleColor::Red;
		cout << "\n\tError: El producto ya existe. Intente añadir el stock.";
		return;
	}

	cout << "\tNombre: "; cin >> nombre;
	cout << "\tTipo: "; cin >> tipo;
	cout << "\tMarca: "; cin >> marca;

	do {
		cout << "\tStock: "; cin >> stock;
	} while (stock <= 0);

	cout << "\tPrecio: "; cin >> precio;

	obj->agregarProducto(codigo_producto, nombre, tipo, marca, stock, precio);

	System::Console::ForegroundColor = System::ConsoleColor::Green;
	cout << "\n\tRegistro exitoso.";
}

void registrarNuevaVenta(controladora* obj) {
	int codigo_venta, codigo_producto, cantidad;
	string fecha, codigo_cliente;

	arrVentaProductos* products = new arrVentaProductos();

	std::cout << "\t\tREGISTRAR UNA NUEVA VENTA\n\n";

	if (!obj->datosSuficientes()) {
		System::Console::ForegroundColor = System::ConsoleColor::Red;
		std::cout << "\n\tError: No hay suficientes datos.";
		return;
	}

	cout << "\tCodigo de venta: "; cin >> codigo_venta;
	cout << "\tFecha: "; cin >> fecha;
	cout << "\tCodigo de cliente: "; cin >> codigo_cliente;

	if (!obj->existeCliente(codigo_cliente)) {
		System::Console::ForegroundColor = System::ConsoleColor::Red;
		cout << "\n\tError: El cliente no existe.";
		return;
	}

	cout << "\n\tEscriba 0 0 para salir\n";

	while (true) {
		System::Console::ForegroundColor = System::ConsoleColor::White;
		cout << "\tCodigo del producto y cantidad: ";
		cin >> codigo_producto >> cantidad;

		if (!codigo_producto && !cantidad) break;

		if (!obj->existeProducto(codigo_producto)) {
			System::Console::ForegroundColor = System::ConsoleColor::Red;
			cout << "\n\tError: El producto no existe.\n";
			continue;
		}

		if (cantidad <= 0) {
			System::Console::ForegroundColor = System::ConsoleColor::Red;
			cout << "\n\tError: Cantidad no válida.\n";
			continue;
		}

		if (!obj->stockSuficiente(codigo_producto, cantidad)) {
			System::Console::ForegroundColor = System::ConsoleColor::Red;
			std::cout << "\n\tError: No hay suficientes existencias.\n";
			continue;
		}

		obj->eliminarStockAlProducto(codigo_producto, cantidad);
		products->agregarProducto(new ventaProductos(codigo_producto, cantidad));
	}

	obj->agregarCompra(codigo_venta, fecha, codigo_cliente, products);

	System::Console::ForegroundColor = System::ConsoleColor::Green;
	cout << "\n\tRegistro exitoso.";
}

void agregarStockAlProducto(controladora* obj) {
	int codigo, cantidad;
	cout << "\t\tAGREGAR STOCK AL PRODUCTO\n\n";

	cout << "\tCodigo del producto: "; cin >> codigo;

	do {
		cout << "\tAgregar cantidad: "; cin >> cantidad;
	} while (cantidad <= 0);

	if (!obj->existeProducto(codigo)) {
		System::Console::ForegroundColor = System::ConsoleColor::Red;
		cout << "\n\tError: El producto no existe.";
		return;
	}

	obj->agregarStockAlProducto(codigo, cantidad);

	System::Console::ForegroundColor = System::ConsoleColor::Green;
	cout << "\n\tOperación exitosa.";
}

void mostrarClientes(controladora* obj) {
	cout << "\t\tMIS CLIENTES\n\n";
	obj->imprimirClientes();
}

void mostrarProductos(controladora* obj) {
	cout << "\t\tMIS PRODUCTOS\n\n";
	obj->eliminarProductos();
}

void mostrarVentas(controladora* obj) {
	cout << "\t\tMIS VENTAS\n\n";
	obj->imprimirVentas();
}

int main() {
	controladora* objControladora = new controladora();
	int opcion;

	while (true) {
		System::Console::ForegroundColor = System::ConsoleColor::White;
		do {
			system("cls");
			mostrarMenu();
			cout << "\tOpcion: "; cin >> opcion;
		} while (opcion < 1 || opcion > 8);

		if (opcion == 8) break;
		system("cls");

		switch (opcion) {
		case 1: registarNuevoCliente(objControladora); break;
		case 2: registrarNuevoProducto(objControladora); break;
		case 3: registrarNuevaVenta(objControladora); break;
		case 4: agregarStockAlProducto(objControladora); break;
		case 5: mostrarClientes(objControladora); break;
		case 6: mostrarProductos(objControladora); break;
		case 7: mostrarVentas(objControladora); break;
		}
		system("pause>0");
	}
	delete objControladora;
	return 0;
}
