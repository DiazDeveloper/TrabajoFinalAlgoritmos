#include "PantallaCreditos.h"

PantallaCreditos::PantallaCreditos() : Entidad(0, 0, "Images/creditos.png", 1, 1)
{
}

void PantallaCreditos::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	ancho = canvas->VisibleClipBounds.Width; 
	alto = canvas->VisibleClipBounds.Height; 
	canvas->DrawImage(sprite, 0, 0, ancho, alto); 
}
