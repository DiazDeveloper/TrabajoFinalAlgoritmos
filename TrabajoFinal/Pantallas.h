#pragma once
#include "Entidad.h"

class Pantallas : public Entidad
{
public:
	Pantallas(); 
	void dibujarImagen(Graphics^ canvas, Bitmap^ sprite,
		Rectangle zoom, Rectangle corte);
};

