#include "Entidad.h"

void Entidad::cambiarImagen(char* nombreArchivo)
{
	strcpy(imagen, nombreArchivo);
	Bitmap^ sprite = gcnew Bitmap(gcnew System::String(imagen));
	ancho = sprite->Width / framesAncho;
	alto = sprite->Height / framesAlto;
	delete sprite;
}

void Entidad::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	canvas->DrawImage(sprite, zoom, corte, GraphicsUnit::Pixel);
}

Entidad::Entidad(int x, int y, char* imagen, int framesAncho, int framesAlto)
{
	this->indiceAlto = 0;
	this->indiceAncho = 0;
	this->x = x;
	this->y = y;
	this->imagen = new char[48];
	this->framesAncho = framesAncho;
	this->framesAlto = framesAlto;
	cambiarImagen(imagen);

}


void Entidad::mostrar(Graphics^ canvas)
{
	Bitmap^ sprite = gcnew Bitmap(gcnew System::String(imagen));
	Rectangle corte = Rectangle(indiceAncho * ancho, indiceAlto * alto, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho, alto);
	dibujarImagen(canvas, sprite, zoom, corte);
}

void Entidad::mover(Graphics^ canvas)
{
}

Rectangle Entidad::getRectangle()
{
	return Rectangle(x, y, alto, ancho);
}

int Entidad::getX()
{
	return x;
}

int Entidad::getY()
{
	return y;
}

int Entidad::getAlto()
{
	return alto;
}

int Entidad::getAncho()
{
	return ancho;
}

bool Entidad::hayColision(Entidad* entidad)
{
	return getRectangle().IntersectsWith(entidad->getRectangle());
}

int Entidad::GetXancho()
{
	return ancho + x;
}

int Entidad::GetYalto()
{
	return alto + y;
}

int Entidad::getVidas()
{
	return vidas;
}

void Entidad::setVidas(int vidas)
{
	this->vidas = vidas;
}

void Entidad::setX(int x)
{
	this->x = x;
}

void Entidad::setY(int y)
{
	this->y = y;
}