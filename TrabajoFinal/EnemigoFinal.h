#pragma once
#include "Entidad.h"
class EnemigoFinal : public Entidad
{
private:
	int vida;
public:
	EnemigoFinal(int x, int y);
	void disparar(Graphics^ canvas);
};


