#pragma once
#include "Entidad.h"
class Shotgun : public Entidad
{
private:
	void dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte);

public:
	Shotgun(int x, int y);
	void setX(int x);  
	void setY(int y);  

};

