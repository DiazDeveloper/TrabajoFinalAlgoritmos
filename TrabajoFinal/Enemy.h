#pragma once
#include "Entidad.h"
class Enemy :  public Entidad
{
private:
	int direccion;
public:
	Enemy(int x, int y, int direccion);
	void mover(Graphics^ canvas);
}; 

