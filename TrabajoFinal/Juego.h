#pragma once
#include "MenuInicio.h"
#include "Background.h"
#include "Player.h" 
#include "Enemy.h"
#include "Shotgun.h"
#include "Bala.h"
#include "EnemigoFinal.h"
#include "Aliado.h"
#include "Pozo.h"
#include "BalaEnemiga.h"
#include "Pantallas.h"
#include "Vidas.h"
#include "PantallaPerder.h"
#include <vector>

class Juego
{
private:
	Background* background;
	MenuInicio* menu;   
	
	Pantallas* pantallaGanadora; 
	PantallasPerder* pantallaPerdedora;
	Player* player;
	Shotgun* escopeta;
	EnemigoFinal* enemigoFinal;  
	Aliado* aliado;  
	vector <Bala*> balas; 
	vector <Enemy*> enemigos; 
	vector <Pozo*> pozos;
	vector <BalaEnemiga*> balasEnemigas;
	vector <Vidas*> vidas;

public:
	Juego(int width, int height);
	void mostrarMenu(Graphics^ canvas);
	void mostrarGanaste(Graphics^ canvas);
	void mostrarPerdiste(Graphics^ canvas);
	void mostrar(Graphics^ canvas); 
	void mover(Graphics^ canvas);
	void moverTeclas(Graphics^ canvas, Movimiento movimiento);
	void mostrarShotgun(Graphics^ canvas); 
	void disparar();
	void generarAliadoPosicionAleatoria(); 
	int getNumeroEnemigos();
	bool PuedeDisparar = false;   
	bool getPuedeDisparar();
	int segundos = 0;
	void SetSegundos(int seg);
	int getSegundos(); 
	bool estaEnPozo;
	bool getEstaEnPozo(); 
	int segundosApoyoBalas;
	void setSegundosApoyoBalas(int seg);
	int getSegundosApoyoBalas();
	void disparoEnemigo();
	int getNumeroDePozos();
	int getVidas(); 
}; 

