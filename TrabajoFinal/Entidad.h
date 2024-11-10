#pragma once
#include <string.h>
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;
enum Movimiento
{
	Arriba, Abajo, Derecha, Izquierda, DiagonalArribaIzquierda, DiagonalArribaDerecha, DiagonalAbajoIzquierda, DiagonalDerechaAbajo 
};

class Entidad
{
protected:
	int x;
	int y;
	int dx, dy;
	int alto, ancho; //w y h
	int indiceAncho, indiceAlto;
	int framesAncho, framesAlto;
	char* imagen;
	int vidas;

	Movimiento movimiento;
	void cambiarImagen(char* nombreDelArchivo);
	virtual void dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte);

public:
	Entidad(int x, int y, char* imagen, int framesAncho, int framesAlto);
	virtual void mostrar(Graphics^ canvas);
	virtual void mover(Graphics^ canvas);
	Rectangle getRectangle();
	int getX();
	int getY();
	int getAlto();
	int getAncho();
	bool hayColision(Entidad* entidad);
	int GetXancho();
	int GetYalto();
	int getVidas();
	void setVidas(int vidas);
	void setX(int x);
	void setY(int y);
};

