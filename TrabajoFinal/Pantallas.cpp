#include "Pantallas.h"

Pantallas::Pantallas() : Entidad(0, 0, "Images/ganaste.png", 1, 1)
{

}

void Pantallas::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	ancho = canvas->VisibleClipBounds.Width;
	alto = canvas->VisibleClipBounds.Height;
	canvas->DrawImage(sprite, 0, 0, ancho, alto);
}
