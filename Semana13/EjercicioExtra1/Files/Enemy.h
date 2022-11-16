#pragma once
#include <iostream>
using namespace System::Drawing;

class Enemy {
private:
	int x, y;
	int dx, dy;
	int idX, idY;
	int width, height;
	int index;
public:
	Enemy(int w, int h, int x, int y) {
		width = w;
		height = h;
		this->x = x;
		this->y = y;
		dx = dy = 20;
		idX = idY = 0;
		index = rand() % 2;
		_sleep(10);
	}
	~Enemy() {}
	void draw(Graphics^ g, Bitmap^ bmpEnemy) {
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmpEnemy, zoom, sectionShown, GraphicsUnit::Pixel);
	}
	void move(Graphics^ g) {
		if (index == 0) {
			//horizontal
			if (x + width * 1.0 > g->VisibleClipBounds.Width || x < 0)
				dx *= -1;
			if (dx > 0) // se mueve a la derecha
				idY = 2;
			else // se mueve a la izquierda
				idY = 1;
			x += dx;
			
		}
		else {
			//vertical
			if (y + height > g->VisibleClipBounds.Height || y < 0)
				dy *= -1;
			if (dy > 0)// va hacia abajo
				idY = 0;
			else // va hacia arriba
				idY = 3;
			y += dy;
		}
		idX++;
		if (idX > 3)
			idX = 0;
	}
};
