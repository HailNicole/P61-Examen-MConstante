#ifndef CIRCULO_H
#define CIRCULO_H

#include <QPoint>

class Circulo : public QPoint
{

private:
    int x;
    int y;
    int tamanio;
public:
    Circulo();
    Circulo(int xpos, int ypos, int tamanio);
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    int getTamanio() const;
    void setTamanio(int newTamanio);
};

#endif // CIRCULO_H
