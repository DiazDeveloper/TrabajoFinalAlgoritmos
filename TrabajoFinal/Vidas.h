#pragma once
#include "Entidad.h"
class Vidas : public Entidad

{
public:
	Vidas(int x, int y); 
	void dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte);
};

