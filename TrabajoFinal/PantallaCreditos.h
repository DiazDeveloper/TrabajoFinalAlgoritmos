#pragma once
#include "Entidad.h"

class PantallaCreditos : public Entidad
{
public:
	PantallaCreditos();   
	void dibujarImagen(Graphics^ canvas, Bitmap^ sprite,
		Rectangle zoom, Rectangle corte);
};

