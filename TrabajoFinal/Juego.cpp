#include "Juego.h"

Juego::Juego(int width, int height)
{
    background = new Background();
    player = new Player(10, 150);
    aliado = new Aliado(400, 150);
    enemigoFinal = new EnemigoFinal(0, 0);
    int aaancho, aalto;
    aaancho = width / 2 - enemigoFinal->getAncho();
    aalto = height / 2 - enemigoFinal->getAlto();

    enemigoFinal->setX(aaancho);
    enemigoFinal->setY(aalto);

    escopeta = new Shotgun(0, 0);
    Random r;

    for (int i = 0; i < 2; i++)
    {
        int direccion = r.Next(1, 4);
        int PosicionX = r.Next(0, width - 102);
        int PosicionY = r.Next(0, height - 102);
        enemigos.push_back(new Enemy(PosicionX, PosicionY, direccion));
    }

    for (int i = 0; i < 4; i++)
    {
        int PosicionX = r.Next(0, width - 120);
        int PosicionY = r.Next(0, height - 100);
        pozos.push_back(new Pozo(PosicionX, PosicionY));
    }

    for (int i = 0; i < player->getVidas(); i++)
    {
        Vidas* vida = new Vidas(0, 0);
        vida->setX(i * vida->getAncho());
        vida->setY(0);  
        vidas.push_back(vida);   
    }

}

void Juego::mostrarMenu(Graphics^ canvas)
{
    menu = new MenuInicio();
    menu->mostrar(canvas);
}

void Juego::mostrarGanaste(Graphics^ canvas)
{
    pantallaGanadora = new Pantallas();
    pantallaGanadora->mostrar(canvas);  
}

void Juego::mostrarPerdiste(Graphics^ canvas)
{
    pantallaPerdedora = new PantallasPerder();
    pantallaPerdedora->mostrar(canvas);
}



void Juego::mostrar(Graphics^ canvas)
{

    background->mostrar(canvas);
    player->mostrar(canvas);

    if (aliado != nullptr)
    {
        aliado->mostrar(canvas);
    }


    for (int i = 0; i < enemigos.size(); i++)
    {
        enemigos[i]->mostrar(canvas);
    }
    for (int i = 0; i < balas.size(); i++)
    {
        balas[i]->mostrar(canvas);
    }

    if (enemigos.size() == 0)
    {
        enemigoFinal->mostrar(canvas);
        for (int i = 0; i < pozos.size(); i++)
        {
            pozos[i]->mostrar(canvas);
        }
         //////////////////////////////////////////// agregado
        for (int i = 0; i < balasEnemigas.size(); i++)
        {
            balasEnemigas[i]->mostrar(canvas);
        }
        //////////////////////////////////////////// agregado
    }

    for (int i = 0; i < vidas.size(); i++)
    {
        vidas[i]->mostrar(canvas);
    }

}


void Juego::mover(Graphics^ canvas)
{
    int totalEnemigos = enemigos.size();
    int totalBalas = balas.size();
    int totalBalasEnemigas = balasEnemigas.size(); ///////////// agregado
    
    // Mover enemigos

    if (enemigos.size() == 0)
    {
        if (aliado != nullptr)
        {
            delete aliado;
            aliado = nullptr;
        }
    }
    for (int i = 0; i < totalEnemigos; i++) {
        enemigos[i]->mover(canvas);

        if (enemigos[i]->hayColision(player))
        {
            player->setX(10);
            player->setY(150);
            player->setVidas(player->getVidas() - 1);  
            int VarApoyoDeLaUltimaVidaParaBorrar = vidas.size() - 1;  
            if (VarApoyoDeLaUltimaVidaParaBorrar > -1)  
            {
                delete vidas[VarApoyoDeLaUltimaVidaParaBorrar];  
                vidas.erase(vidas.begin() + VarApoyoDeLaUltimaVidaParaBorrar);
            }

        }
    }

    if (aliado != nullptr && player->hayColision(aliado))
    {

        PuedeDisparar = true;
        delete aliado;
        aliado = nullptr;

        if (totalEnemigos > 0)
        {
            generarAliadoPosicionAleatoria();
        }
    }
    // Mover balas y verificar colisiones
    for (int i = totalBalas - 1; i >= 0; i--) {
        balas[i]->mover(canvas);

        // Verificar colisión de bala con enemigos
        for (int j = totalEnemigos - 1; j >= 0; j--) {
            if (balas[i]->hayColision(enemigos[j])) {
                delete balas[i];
                delete enemigos[j];

                balas.erase(balas.begin() + i);
                enemigos.erase(enemigos.begin() + j);

                totalBalas--;
                totalEnemigos--;
                break;
            }
        }

        if (i < totalBalas)
        {
            if (balas[i]->getX() < 0 ||
                balas[i]->GetXancho() > canvas->VisibleClipBounds.Width ||
                balas[i]->getY() < 0 ||
                balas[i]->GetYalto() > canvas->VisibleClipBounds.Height) {

                delete balas[i];
                balas.erase(balas.begin() + i);
                totalBalas--;
            }
        }
    }
    /////////////////////// agregado
    for (int i = totalBalasEnemigas - 1; i >= 0; i--)
    {
        balasEnemigas[i]->mover(canvas);
        if (balasEnemigas[i]->hayColision(player))
        {

            player->setX(10);
            player->setY(150);
            player->setVidas(player->getVidas() - 1); 
            int VarApoyoDeLaUltimaVidaParaBorrar = vidas.size() - 1; 
            if (VarApoyoDeLaUltimaVidaParaBorrar > -1) 
            {
                delete vidas[VarApoyoDeLaUltimaVidaParaBorrar];
                vidas.erase(vidas.begin() + VarApoyoDeLaUltimaVidaParaBorrar);
            }

            delete balasEnemigas[i];
            balasEnemigas.erase(balasEnemigas.begin() + i);
            totalBalasEnemigas--;
            break;

        }
    }
    ////////////////////// agregado

    for (int i = 0; i < pozos.size(); i++)
    {
        if (player->hayColision(pozos[i]))
        {
            estaEnPozo = true;
            if (segundos == 4)
            {
                delete pozos[i];
                pozos.erase(pozos.begin() + i);
            }
        }
        else
        {
            estaEnPozo = false;
        }
    }

}


void Juego::moverTeclas(Graphics^ canvas, Movimiento movimiento)
{
    player->MoverTeclar(canvas, movimiento);

}

void Juego::mostrarShotgun(Graphics^ canvas)
{
    escopeta->setX(player->getX());
    escopeta->setY(player->getY() + 55);
    escopeta->mostrar(canvas);
}

void Juego::disparar()
{
    if (balas.size() < 3 && PuedeDisparar)
    {
        balas.push_back(new Bala(player->getX() + 50, player->getY() + 30, player->getMovimiento()));
        PuedeDisparar = false;
    }
}



void Juego::generarAliadoPosicionAleatoria()
{

    Random r1, r2;
    int posX = r1.Next(100, 800);
    int posY = r2.Next(100, 300);

    aliado = new Aliado(posX, posY);
}

int Juego::getNumeroEnemigos()
{
    return enemigos.size();
}

bool Juego::getPuedeDisparar()
{
    return PuedeDisparar;
}

void Juego::SetSegundos(int seg)
{
    this->segundos = seg;
}

int Juego::getSegundos()
{
    return segundos;
}

bool Juego::getEstaEnPozo()
{
    return estaEnPozo;
}

void Juego::setSegundosApoyoBalas(int seg)
{
    this->segundos = seg;
}

int Juego::getSegundosApoyoBalas()
{
    return segundosApoyoBalas;
}

void Juego::disparoEnemigo() // agregado
{
        Random r;
        int direccion = r.Next(1, 4);
        balasEnemigas.push_back(new BalaEnemiga(enemigoFinal->getX(), enemigoFinal->getY(), direccion));

}

int Juego::getNumeroDePozos()
{
    return pozos.size();
}

int Juego::getVidas()
{
    return player->getVidas();
}
