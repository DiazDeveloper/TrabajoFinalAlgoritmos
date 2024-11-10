#include "Aliado.h"

Aliado::Aliado(int x, int y) : Entidad(x, y, "Images/companero.png", 1, 1) 
{
}

void Aliado::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
    ancho = 80;
    alto = 120; 
    canvas->DrawImage(sprite, x, y, ancho, alto);
}


