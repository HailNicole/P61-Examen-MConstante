#include "juego.h"
#include "ui_juego.h"

Juego::Juego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
    QPoint centro = ui->marco->geometry().center();
    m_circulo = new Circulo();
    m_circulo->setX(centro.x());
    m_circulo->setY(centro.y());
    dibujar_circulo();
}

Juego::~Juego()
{
    delete ui;
}

void Juego::on_btnArriba_released()
{
    m_circulo->setY(m_circulo->getY()-1);
    dibujar_circulo();
}


void Juego::on_btnAbajo_released()
{

}


void Juego::on_btnIzqueirda_released()
{

}


void Juego::on_btnDerecha_released()
{

}


void Juego::on_actionConfigraci0n_triggered()
{
    Configuracion *config = new Configuracion(this);
    int respuesta = config->exec();
    if (respuesta){
        qDebug() << config->color().name();
        qDebug() << config->dimension();
    }
}

void Juego::on_actionSalir_triggered()
{
    this->close();
}

void Juego::dibujar_circulo()
{
    QPainter painter(this);
    QPen pincel;
    pincel.setColor(Qt::red);
    pincel.setWidth(4);
    pincel.setJoinStyle(Qt::MiterJoin);

    painter.setPen(pincel);
    painter.drawEllipse(m_circulo->getX(),m_circulo->getY(),m_circulo->getTamanio(), m_circulo->getTamanio());
    update();
}
