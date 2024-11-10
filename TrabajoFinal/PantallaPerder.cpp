#include "PantallaPerder.h"

PantallasPerder::PantallasPerder() : Entidad(0, 0, "Images/perdiste.png", 1, 1)
{
}

void PantallasPerder::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	ancho = canvas->VisibleClipBounds.Width; 
	alto = canvas->VisibleClipBounds.Height; 
	canvas->DrawImage(sprite, 0, 0, ancho, alto); 
}
