#pragma once
#include "arrProductos.h"
#include "arrClientes.h"
#include "arrVentas.h"

class controladora {
private:
	arrClientes* objArrCliente;
	arrProductos* objArrProductos;
	arrVentas* objArrVentas;
public:
	controladora() {
		this->objArrCliente = new arrClientes();
		this->objArrProductos = new arrProductos();
		this->objArrVentas = new arrVentas();
	}

	~controladora() {
		delete this->objArrCliente, this->objArrProductos, this->objArrVentas;
	}

	void agregarCliente(string id, string name) {
		this->objArrCliente->agregarCliente(new Cliente(id, name));
	}

	void agregarProducto(int id, string name, string type, string brand, int stock, float price) {
		this->objArrProductos->agregarProducto(new producto(id, name, type, brand, stock, price));
	}

	void agregarCompra(int id, string date, string clientId, arrVentaProductos* products) {
		this->objArrVentas->agregarVenta(new venta(id, date, clientId, products));
	}

	void agregarStockAlProducto(int id, int quantity) {
		for (int i = 0; i < this->objArrProductos->getNumeroProductos(); ++i) {
			if (this->objArrProductos->getProductoSegunPosicion(i)->getCodigoNombre() != id) continue;
			this->objArrProductos->getProductoSegunPosicion(i)->agregarStock(quantity);
			break;
		}
	}

	void eliminarStockAlProducto(int id, int quantity) {
		for (int i = 0; i < this->objArrProductos->getNumeroProductos(); ++i) {
			if (this->objArrProductos->getProductoSegunPosicion(i)->getCodigoNombre() != id) continue;
			this->objArrProductos->getProductoSegunPosicion(i)->eliminarStock(quantity);
			break;
		}
	}

	void imprimirClientes() {
		for (int i = 0; i < this->objArrCliente->getNumeroClientes(); ++i) {
			cout << "\tId: " << this->objArrCliente->getClienteSegunPosicion(i)->getDNI() << " - Name: " << this->objArrCliente->getClienteSegunPosicion(i)->getNombre() << '\n';
		}
	}

	void eliminarProductos() {
		for (int i = 0; i < this->objArrProductos->getNumeroProductos(); ++i) {
			cout << '\t';
			this->objArrProductos->getProductoSegunPosicion(i)->toString();
		}
	}

	void imprimirVentas() {
		for (int i = 0; i < this->objArrVentas->getNumeroVentas(); ++i) {
			this->objArrVentas->getVentaSegunPosicion(i)->toString();
		}
	}

	bool existeCliente(string id) {
		for (int i = 0; i < this->objArrCliente->getNumeroClientes(); ++i) {
			if (this->objArrCliente->getClienteSegunPosicion(i)->getDNI() == id) return true;
		}
		return false;
	}

	bool existeProducto(int id) {
		for (int i = 0; i < this->objArrProductos->getNumeroProductos(); ++i) {
			if (this->objArrProductos->getProductoSegunPosicion(i)->getCodigoNombre() == id) return true;
		}
		return false;
	}

	bool datosSuficientes() {
		return this->objArrCliente->getNumeroClientes() != 0 && this->objArrProductos->getNumeroProductos() != 0;
	}

	bool stockSuficiente(int productId, int quantity) {
		for (int i = 0; i < this->objArrProductos->getNumeroProductos(); ++i) {
			if (this->objArrProductos->getProductoSegunPosicion(i)->getCodigoNombre() != productId) continue;
			if (this->objArrProductos->getProductoSegunPosicion(i)->getStock() < quantity) return false;
			return true;
		}
	}
};
