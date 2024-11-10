#include "Pozo.h"

Pozo::Pozo(int x, int y) : Entidad(x, y, "Images/pozo.png", 1, 1) 
{
}

void Pozo::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
    ancho = 120;
    alto  = 100;
    canvas->DrawImage(sprite, x, y, ancho, alto); 
}
