#pragma once
#include "Entidad.h"

class Background : public Entidad
{
public:
	Background();
	void dibujarImagen(Graphics^ canvas, Bitmap^ sprite,
		Rectangle zoom, Rectangle corte);
};

