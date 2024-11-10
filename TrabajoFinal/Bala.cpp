#include "Bala.h"

void Bala::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	ancho = alto = 60; 
	canvas->DrawImage(sprite, x, y, ancho, alto); 
}

Bala::Bala(int x, int y, Movimiento movimiento) : Entidad(x, y, "Images/Bala.png", 1, 1)
{
	this->movimiento = movimiento;  
	dx = dy = 70; 
}

void Bala::mover(Graphics^ canvas)
{
	switch (movimiento)
	{
	case Arriba:
		y -= dy;
		break;
	case Abajo:
		y += dy;
		break;
	case Derecha:
		x += dx;
		break;
	case Izquierda:
		x -= dx;
		break;
	case DiagonalAbajoIzquierda:
		x -= dx;
		y += dy;
		break;
	case DiagonalArribaDerecha:
		x += dx;
		y -= dy;
		break;
	case DiagonalDerechaAbajo:
		x += dx;
		y += dy;
		break;
	case DiagonalArribaIzquierda:
		x -= dx;
		y -= dy;
		break;
	default:
		break;
	}
}
