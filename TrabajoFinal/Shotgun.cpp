#include "Shotgun.h"


void Shotgun::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	Entidad::dibujarImagen(canvas, sprite, zoom, corte); 
}

Shotgun::Shotgun(int x, int y) : Entidad(x, y, "Images/shotgun.png", 1, 1)
{

}

void Shotgun::setX(int x)
{
	this->x = x;
}

void Shotgun::setY(int y)
{
	this->y = y; 
}

