#pragma once
#include "Entidad.h"

class PantallasPerder : public Entidad
{
public:
	PantallasPerder();  
	void dibujarImagen(Graphics^ canvas, Bitmap^ sprite,
		Rectangle zoom, Rectangle corte);
};

