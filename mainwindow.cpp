#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    drawField = new ObszarRysowania();
    setFileName("picture");
    connect(ui->red, SIGNAL (clicked()), drawField, SLOT (on_red_clicked()));
    connect(ui->green, SIGNAL (clicked()), drawField, SLOT (on_green_clicked()));
    connect(ui->blue, SIGNAL (clicked()), drawField, SLOT (on_blue_clicked()));
    connect(ui->yellow, SIGNAL (clicked()), drawField, SLOT (on_yellow_clicked()));
    connect(ui->erase, SIGNAL (clicked()), drawField, SLOT (on_erase_clicked()));
    connect(ui->save, SIGNAL (triggered()), drawField, SLOT (on_save_clicked(const QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete drawField;
}
void MainWindow::setFileName(QString name)
{
    this->fileName = name;
}
