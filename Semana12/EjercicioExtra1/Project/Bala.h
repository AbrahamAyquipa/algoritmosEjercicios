#pragma once
#include <iostream>
using namespace System::Drawing;

class Bala {
private:
	int x, y;
	int dx, dy;
	int idX, idY;
	int width, height;
	bool visibility;
public:
	Bala(int w, int h) {
		width = w;
		height = h;
		dx = dy = 20;
		x = 100; 
		y = 100;
		idX = idY = 0;
		visibility = true;
	}

	~Bala() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShow = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width, height);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}

	void move(Graphics^ g) {
		if (x + width * 1.0 > g->VisibleClipBounds.Width || x < 0) {
			dx *= -1;
			//visibility = false;
		}
		if (dx > 0) idY = 2;
		else idY = 1;
		x += dx;

		if (y + height * 1.0 > g->VisibleClipBounds.Height || y < 0) {
			dy *= -1;
			//visibility = false;
		}
		if (dy > 0) idY = 0;
		else idY = 3;
		y += dy;

		idX++;
		if (idX > 3) idX = 0;

		if (y < 0) { visibility = false; }
	}

	bool getVisibility() { return visibility; }
};
