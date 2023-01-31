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

    lienzo = new QImage(ui->marco->size(), QImage::Format_ARGB32_Premultiplied);
    lienzo->fill(Qt::white);
    m_painter2 = new QPainter(lienzo);
    m_painter2->setRenderHint(QPainter::Antialiasing);
    m_col=Qt::red;
    m_dim=4;
    dibujar_circulo();
}

Juego::~Juego()
{
    delete ui;
}

void Juego::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    int x = ui->marco->geometry().x();
    int y = ui->marco->geometry().y();
    painter.drawImage(x,y+22,*lienzo);
    event->accept();
}

void Juego::on_btnArriba_released()
{
    m_circulo->setY(m_circulo->getY()-1);
    int a = ui->marco->geometry().y()-7;
    if(m_circulo->getY() <= a){
        QMessageBox::information(this, "Error", "Fuera de los limites");
        return;
    }else{
        dibujar_circulo();
    }
}

void Juego::on_btnAbajo_released()
{
    m_circulo->setY(m_circulo->getY()+1);
    if(m_circulo->getY() >= 248){
        QMessageBox::information(this, "Error", "Fuera de los limites");
        return;
    }else{
        dibujar_circulo();
    }
}


void Juego::on_btnIzqueirda_released()
{
    m_circulo->setX(m_circulo->getX()-1);
    int b = ui->marco->geometry().x()-7;
    if(m_circulo->getX() <= b){
        QMessageBox::information(this, "Error", "Fuera de los limites");
        return;
    }else{
        dibujar_circulo();
    }
}


void Juego::on_btnDerecha_released()
{
    m_circulo->setX(m_circulo->getX()+1);
    if(m_circulo->getX() >= 348){
        QMessageBox::information(this, "Error", "Fuera de los limites");
        return;
    }else{
        dibujar_circulo();
    }
}

void Juego::on_actionConfigraci0n_triggered()
{
    Configuracion *config = new Configuracion(this);
    int respuesta = config->exec();
    if (respuesta){
        qDebug() << config->color().name();
        qDebug() << config->dimension();
    }
    m_col=config->color().name();
    m_dim = config->dimension();
    dibujar_circulo();
}

void Juego::on_actionSalir_triggered()
{
    this->close();
}

void Juego::dibujar_circulo()
{
    lienzo->fill(Qt::white);
    QPen pincel;
    pincel.setColor(m_col);
    pincel.setWidth(m_dim);
    pincel.setJoinStyle(Qt::MiterJoin);

    m_painter2->setPen(pincel);
    m_painter2->drawEllipse(m_circulo->getX(),m_circulo->getY(),m_circulo->getTamanio(), m_circulo->getTamanio());
    update();
}
