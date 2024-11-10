#include "Vidas.h"

Vidas::Vidas(int x, int y) : Entidad(x, y, "Images/1vida.png", 1, 1)
{
}

void Vidas::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	ancho = 70;
	alto = 70;
	canvas->DrawImage(sprite, x, y, ancho, alto);
}
