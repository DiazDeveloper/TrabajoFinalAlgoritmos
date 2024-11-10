#include "Player.h"

Player::Player(int x, int y) : Entidad(x, y, "Images/red.png", 3, 8)
{
	dx = dy = 25;  // movimiento jugador 
	movimiento = Abajo;
	vidas = 3;
}

void Player::MoverTeclar(Graphics^ canvas, Movimiento movimiento)
{
	this->movimiento = movimiento;
	switch (movimiento)
	{
	case Arriba:
		y -= dy;
		indiceAlto = 0;
		break;

	case DiagonalArribaDerecha:
		indiceAlto = 1;
		x += dx;
		y -= dy;
		break;

	case Derecha: 
		x += dx;
		indiceAlto = 2;
		break;

	case DiagonalDerechaAbajo: 
		indiceAlto = 3;
		x += dx;
		y += dy;
		break;

	case Abajo:
		y += dy;
		indiceAlto = 4;
		break;
	
	case DiagonalAbajoIzquierda: 
		indiceAlto = 5;
		x -= dx;
		y += dy;
		break;

	case Izquierda:
		x -= dx;
		indiceAlto = 6;
		break;
	
	case DiagonalArribaIzquierda:
		indiceAlto = 7;
		x -= dx;
		y -= dy;
		break;
	default:
		break;
	}
	if (x < 0)
	{
		x = 0;
	}

	if (y < 0)
	{
		y = 0;
	}

	if (x + ancho > canvas->VisibleClipBounds.Width)
	{
		x = canvas->VisibleClipBounds.Width - ancho;
	}

	if (y + alto > canvas->VisibleClipBounds.Height)
	{
		y = canvas->VisibleClipBounds.Height - alto;
	}

	indiceAncho++;
	if (indiceAncho > 2)
	{
		indiceAncho = 0;
	}

}

Movimiento Player::getMovimiento()
{
	return movimiento;
}
