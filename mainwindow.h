#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <obszarrysowania.h>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString fileName;
    ObszarRysowania* drawField;
    void setFileName(QString name);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
