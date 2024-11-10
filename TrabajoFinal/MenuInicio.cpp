#include "MenuInicio.h"

MenuInicio::MenuInicio() :Entidad(0, 0, "Images/menu1.png", 1, 1)
{
}

void MenuInicio::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	ancho = canvas->VisibleClipBounds.Width;
	alto = canvas->VisibleClipBounds.Height;
	canvas->DrawImage(sprite, 0, 0, ancho, alto);
}
