#pragma once
#include "Entidad.h"
class Pozo : public Entidad
{
public:
	Pozo(int x, int y);  
	void dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte); 
};

