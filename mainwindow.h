#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <obszarrysowania.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ObszarRysowania* drawField;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
