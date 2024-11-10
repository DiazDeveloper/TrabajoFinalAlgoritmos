#pragma once
#include "Entidad.h"
class Player :  public Entidad
{
public:
	Player(int x, int y);
	void MoverTeclar(Graphics^ canvas, Movimiento movimiento);
	Movimiento getMovimiento();
};

