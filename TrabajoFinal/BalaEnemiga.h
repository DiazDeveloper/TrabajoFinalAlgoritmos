#pragma once
#include "Entidad.h"
class BalaEnemiga : public Entidad
{
private:
	int direccion;
public:
	BalaEnemiga(int x, int y, int direccion);
	void mover(Graphics^ canvas);
	void dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte); 
};

