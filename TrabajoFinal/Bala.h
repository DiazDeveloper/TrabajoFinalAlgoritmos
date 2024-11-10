#pragma once
#include "Entidad.h"
class Bala : public Entidad
{
private:
	void dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte);
public:
	Bala(int x, int y, Movimiento movimiento);
	void mover(Graphics^ canvas); 
};
