#include "Menu.h"

Menu::Menu() :Entidad(0, 0, "Images/menu.png", 1, 1)
{
}

void Menu::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	ancho = canvas->VisibleClipBounds.Width;
	alto = canvas->VisibleClipBounds.Height;
	canvas->DrawImage(sprite, 0, 0, ancho, alto);
}
