#include "configuracion.h"
#include "ui_configuracion.h"

Configuracion::Configuracion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuracion)
{
    ui->setupUi(this);
     m_color.setRgb(m_color.red(),m_color.green(), m_color.blue());
    setWidgetColor();
}

Configuracion::~Configuracion()
{
    delete ui;
}

void Configuracion::on_btnColor_released()
{

}

void Configuracion::setColor(const QColor &newColor)
{
    m_color = newColor;
}

void Configuracion::setDimension(int newDimension)
{
    m_dimension = newDimension;
}

void Configuracion::setWidgetColor()
{
    int r = m_color.red();
    int g = m_color.green();
    int b = m_color.blue();
    QString style = "background-color: rgb(" + QString::number(r) + ", " + QString::number(g) + ", " + QString::number(b) + ")";
    ui->wigetColor->setStyleSheet(style);
}

const QColor &Configuracion::color() const
{
    return m_color;
}

int Configuracion::dimension() const
{
    return m_dimension;
}


void Configuracion::on_inDimension_sliderReleased()
{
    m_dimension = ui->inDimension->value();
}


void Configuracion::on_btnColor_clicked()
{
    m_color = QColorDialog::getColor(m_color,
                                       this,
                                       "Color del pincel");
    m_color.setRgb(m_color.red(),m_color.green(), m_color.blue());
}
