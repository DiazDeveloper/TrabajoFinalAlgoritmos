#include "Enemy.h"

Enemy::Enemy(int x, int y, int direccion) : Entidad(x, y, "Images/grimer.png",3 , 8)
{
	dx = dy = 15;
	this->direccion = direccion;
}

void Enemy::mover(Graphics^ canvas)
{
	if (direccion == 1)
	{
		if (x + ancho > canvas->VisibleClipBounds.Width || x < 0)
		{
			dx *= -1;
		}
		indiceAlto = dx > 0 ? 7 : 6; // basicamente dice, si dx es mayor q 0? si lo es, 
		                             // entonces el indice es 2, caso contrario es 1
		x += dx;
	}

	else if (direccion == 2)
	{
		if (y + alto > canvas->VisibleClipBounds.Height || y < 0)
		{
			dy *= -1;
		}
		indiceAlto = dy > 0 ? 0 : 1;
		y += dy;
	}

	else if (direccion == 3) // diagonal izquerda abajo y diagonal derecha arriba
	{
		if (y + alto > canvas->VisibleClipBounds.Height || y < 0)
		{
			dy *= -1;
		}

		if (x + ancho > canvas->VisibleClipBounds.Width || x < 0)
		{
			dx *= -1;
		}

		if (dx > 0 && dy > 0)
		{
			indiceAlto = 5;
		}

		if (dx < 0 && dy < 0)
		{
			indiceAlto = 2;
		}

		else if (dx > 0 && dy < 0)
		{
			indiceAlto = 3; 
		}
		else if (dx < 0 && dy > 0)
		{
			indiceAlto = 4; 
		}
		x += dx;
		y += dy;

	}

	indiceAncho++;
	if (indiceAncho > 2)
	{
		indiceAncho = 0;
	}
}
