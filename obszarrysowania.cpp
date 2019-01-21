#include "obszarrysowania.h"
#include <QDebug>
ObszarRysowania::ObszarRysowania(QWidget *parent) : QWidget(parent)
{

}

void ObszarRysowania::on_red_clicked()
{
     qDebug() << "Kolor: " << "czerwony";
}
void ObszarRysowania::on_blue_clicked()
{
    qDebug() << "Kolor: " << "niebieski";
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
    qDebug() << "Czynność: " << "Zapisywanie";
    return true;
}
