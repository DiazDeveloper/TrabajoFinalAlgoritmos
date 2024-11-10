#pragma once
#include "Entidad.h"
class Aliado : public Entidad
{
public:
	Aliado(int x, int y);
	void dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte);
}; 

