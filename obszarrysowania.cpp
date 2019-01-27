#include "obszarrysowania.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>
ObszarRysowania::ObszarRysowania(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
}

void ObszarRysowania::on_red_clicked()
{
     qDebug() << "Kolor: " << "czerwony";
}
void ObszarRysowania::on_blue_clicked()
{
    qDebug() << "Kolor: " << "niebieski";
    this->mKolor = Qt::red;
}
void ObszarRysowania::on_yellow_clicked()
{
    qDebug() << "Kolor: " << "żółty";
}
void ObszarRysowania::on_green_clicked()
{
    qDebug() << "Kolor: " << "zielony";

}
void ObszarRysowania::on_erase_clicked()
{
    qDebug() << "Czynność: " << "Usuwanie";

}
bool ObszarRysowania::on_save_clicked(const QString &fileName)
{
    qDebug() << "Czynność: " << "Zapisywanie" << fileName;
    return true;
}
void ObszarRysowania::mousePressEvent(QMouseEvent *zdarzenie)
{
    if (zdarzenie->buttons()==Qt::LeftButton)
    {
        qDebug() << "Nastąpiło kliknięcie lewego przycisku: " << zdarzenie;
    }
    if (zdarzenie->buttons()==Qt::RightButton)
    {
        qDebug() << "Nastąpiło kliknięcie prawego przycisku: " << zdarzenie;
    }
}
void ObszarRysowania::mouseMoveEvent(QMouseEvent *zdarzenie)
{
    qDebug() << "Pozycja myszy: " << zdarzenie->pos();
}
void ObszarRysowania::mouseReleaseEvent(QMouseEvent *zdarzenie)
{
    if (zdarzenie->buttons()==Qt::NoButton)
    {
        qDebug() << "Nastąpiło uwolnienie przycisku: " << zdarzenie;
    }
}
void ObszarRysowania::paintEvent(QPaintEvent *zdarzenie)
{
    qDebug() << "Nastąpiło rysowanie: " << zdarzenie;
}
void ObszarRysowania::resizeEvent(QResizeEvent *zdarzenie)
{
    if (zdarzenie->size()!= zdarzenie->oldSize())
    {
        qDebug() << "Nastąpiła zmiana rozmiaru okna: " << zdarzenie;
    }
}
