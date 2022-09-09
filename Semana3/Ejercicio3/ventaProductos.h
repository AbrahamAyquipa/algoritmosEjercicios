#pragma once

class ventaProductos {
private:
	int codigo_producto;
	int cantidad;
public:
	ventaProductos(int codigo_producto, int cantidad) {
		this->codigo_producto = codigo_producto;
		this->cantidad = cantidad;
	}

	~ventaProductos() { }

	int getCodigoProducto() {
		return this->codigo_producto;
	}

	int getCantidad() {
		return this->cantidad;
	}
};
