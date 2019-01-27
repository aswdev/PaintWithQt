#include "obszarrysowania.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPaintEvent>
#include <qpainter.h>
#include <QResizeEvent>
#include <QFileDialog>

ObszarRysowania::ObszarRysowania(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
}
ObszarRysowania::~ObszarRysowania()
{
    //
}
void ObszarRysowania::on_red_clicked()
{
     qDebug() << "Kolor: " << "czerwony";
     this->mKolor = Qt::red;
}
void ObszarRysowania::on_blue_clicked()
{
    qDebug() << "Kolor: " << "niebieski";
    this->mKolor = Qt::blue;
}
void ObszarRysowania::on_yellow_clicked()
{
    qDebug() << "Kolor: " << "żółty";
    this->mKolor = Qt::yellow;
}
void ObszarRysowania::on_green_clicked()
{
    qDebug() << "Kolor: " << "zielony";
    this->mKolor = Qt::green;
}
void ObszarRysowania::on_erase_clicked()
{
    qDebug() << "Czynność: " << "Usuwanie";
    int x = QWidget::width();
    int y = QWidget::height();
    QImage erased = QImage();
    erased = QImage(x, y, QImage::Format_ARGB32);
    erased.fill(QColor(255, 255, 255));
    this->mRysunek = erased;
    this->update();

}
bool ObszarRysowania::on_save_clicked()
{
    qDebug() << "Czynność: " << "Zapisywanie" << fileName;
    QString fileName = QFileDialog::getSaveFileName(this,tr("Zapisz obraz"), "", tr("PNG (*.png);;Wszystkie pliki (*)"));
    if (fileName.isEmpty())
    {
            qDebug() << "Wystąpił błąd podczas tworzenia pliku.";

            return false;
    }
    else
    {
        mRysunek.save(fileName, "PNG");
        qDebug() << "Pomyślnie utworzono plik: " << fileName;

        return true;
    }
}
void ObszarRysowania::mousePressEvent(QMouseEvent *zdarzenie)
{
    if (zdarzenie->buttons()==Qt::LeftButton)
    {
        qDebug() << "Nastąpiło kliknięcie lewego przycisku: " << zdarzenie;
        mRysowanie = true;
    }
    if (zdarzenie->buttons()==Qt::RightButton)
    {
        qDebug() << "Nastąpiło kliknięcie prawego przycisku: " << zdarzenie;
        mRysowanie = false;
    }
}
void ObszarRysowania::mouseMoveEvent(QMouseEvent *zdarzenie)
{
    if(this->mRysowanie == true && zdarzenie->buttons()==Qt::LeftButton)
    {
        qDebug() << "Pozycja pędzla: " << zdarzenie->pos();

        QPainter rysownik;
        rysownik.begin(this);
        rysownik.setPen(QPen(this->mKolor, 12, Qt::DashDotLine, Qt::RoundCap));
        rysownik.drawLine(*oldX, *oldY, zdarzenie->x(), zdarzenie->y());
        *oldX = zdarzenie->x();
        *oldY = zdarzenie->y();
        rysownik.end();

        repaint();

    }
}
void ObszarRysowania::mouseReleaseEvent(QMouseEvent *zdarzenie)
{
    if (zdarzenie->buttons()==Qt::NoButton)
    {
        qDebug() << "Nastąpiło uwolnienie przycisku: " << zdarzenie;
        mRysowanie = false;
    }
}
void ObszarRysowania::paintEvent(QPaintEvent *zdarzenie)
{
    qDebug() << "Nastąpiło rysowanie: " << zdarzenie;
    QPainter rysownik;
    rysownik.begin(this);
    rysownik.drawImage(0, 0, mRysunek);
    rysownik.end();

}
void ObszarRysowania::resizeEvent(QResizeEvent *zdarzenie)
{
    if (zdarzenie->size()!= zdarzenie->oldSize())
    {
        qDebug() << "Nastąpiła zmiana rozmiaru okna: " << zdarzenie;
        int x = QWidget::width();
        int y = QWidget::height();
        QImage erased = QImage();
        erased = QImage(x, y, QImage::Format_ARGB32);
        erased.fill(QColor(255, 255, 255));
        this->mRysunek = erased;
        this->update();
        this->update();

    }
}
