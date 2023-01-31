#include "circulo.h"

int Circulo::getX() const
{
    return x;
}

void Circulo::setX(int newX)
{
    x = newX;
}

int Circulo::getY() const
{
    return y;
}

void Circulo::setY(int newY)
{
    y = newY;
}

int Circulo::getTamanio() const
{
    return tamanio;
}

void Circulo::setTamanio(int newTamanio)
{
    tamanio = newTamanio;
}

Circulo::Circulo()
    :QPoint(0,0)
{
    x=0;
    y=0;
    tamanio=80;
}

Circulo::Circulo(int xpos, int ypos, int tamanio)
    :QPoint(xpos, ypos), tamanio(tamanio)
{
    this->x = xpos;
    this->y = ypos;
    this->tamanio = tamanio;
}
