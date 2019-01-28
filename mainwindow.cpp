#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->on_red_clicked();

    setFileName("picture");
    connect(ui->red, SIGNAL (clicked()), this->ui->widget, SLOT (on_red_clicked()));
    connect(ui->green, SIGNAL (clicked()), this->ui->widget, SLOT (on_green_clicked()));
    connect(ui->blue, SIGNAL (clicked()), this->ui->widget, SLOT (on_blue_clicked()));
    connect(ui->yellow, SIGNAL (clicked()), this->ui->widget, SLOT (on_yellow_clicked()));
    connect(ui->erase, SIGNAL (clicked()), this->ui->widget, SLOT (on_erase_clicked()));
    connect(ui->save, SIGNAL (triggered()), this->ui->widget, SLOT (on_save_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setFileName(QString name)
{
    this->fileName = name;
}
