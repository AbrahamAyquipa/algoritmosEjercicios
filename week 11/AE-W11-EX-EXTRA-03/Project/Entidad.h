#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;
using namespace System::Drawing;

public enum direccion { up, down, left, right, none };

class Entidad {
protected:
	int x, y, dx, dy, w, h;
	int row, col, maxRow, maxCol;
	direccion orientacion;
	bool active;
public:
	Entidad() {
		dx = 0;
		dy = 0;
		active = true;
		orientacion = direccion::none;
	}

	Entidad(int x, int y, int col, int row, int maxCol, int maxRow) {
		this->x = x;
		this->y = y;
		this->col = col;
		this->row = row;
		this->maxCol = maxCol;
		this->maxRow = maxRow;

		orientacion = direccion::none;
		dx = 0;
		dy = 0;
		active = true;
	}

	Entidad(int col, int row, int maxCol, int maxRow) {
		this->col = col;
		this->row = row;
		this->maxCol = maxCol;
		this->maxRow = maxRow;

		orientacion = direccion::none;
		dx = 0;
		dy = 0;
		active = true;
	}

	~Entidad() {}

	virtual void mostrar(Graphics^ g, Bitmap^ bmp) {
		w = bmp->Width / maxCol;
		h = bmp->Height / maxRow;
		Rectangle porcion = Rectangle(col * w, row * h, w, h);

		g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);

		col++;
		if (col == maxCol) col = 0;
	}

	virtual void mover(Graphics^ g) {
		if (x + dx >= 0 && x + w + dx < g->VisibleClipBounds.Width) x += dx;
		if (y + dy >= 0 && y + h + dy < g->VisibleClipBounds.Height) y += dy;
	}

	virtual void desplazamiento(direccion d) {
		dx = 0;
		dy = 0;
		orientacion = d;

		switch (d) {
		case direccion::up:
			dy = -10;
			row = 3;
			break;
		case direccion::down:
			dy = 10;
			row = 0;
			break;
		case direccion::left:
			dx = -10;
			row = 1;
			break;
		case direccion::right:
			dx = 10;
			row = 2;
		}
	}

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setDx(int dx) {this->dx = dx;}
	void setDy(int dy) { this->dy = dy; }
	void setW(int w) { this->w = w; }
	void setH(int h) { this->h = h; }
	void setRow(int r) { this-> row = r; }
	void setCol(int c) { this->col = c; }
	void setMaxRow(int r) { this->maxRow = r; }
	void setMaxCol(int c) { this->maxCol = c; }
	void setActive(bool state) { this->active = state; }
	void setOrientacion(direccion d) { this->orientacion = d; }

	int getX() { return x; }
	int getY() { return y; }
	int getDx() { return dx; }
	int getDy() { return dy; }
	int getW() { return w; }
	int getH() { return h; }
	int getRow() { return row; }
	int getCol() { return col; }
	int getMaxRow() { return maxRow; }
	int getMaxCol() { return maxCol; }
	bool getActive() { return active; }
	direccion getOrientacion() { return orientacion; }
	Rectangle getArea() { return Rectangle(x, y, w, h); }
	Rectangle getNextArea() { return Rectangle(x + dx, y + dy, w, h); }
};
