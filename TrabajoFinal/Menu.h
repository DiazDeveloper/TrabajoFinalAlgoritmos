#pragma once
#include "Entidad.h"
class Menu : public Entidad
{
public:
	Menu();
	void dibujarImagen(Graphics^ canvas, Bitmap^ sprite,
		Rectangle zoom, Rectangle corte);   
};

