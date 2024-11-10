#pragma once
#include "Entidad.h"
class MenuInicio : public Entidad
{
public:
	MenuInicio(); 
	void dibujarImagen(Graphics^ canvas, Bitmap^ sprite,
		Rectangle zoom, Rectangle corte);
};

