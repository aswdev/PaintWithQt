#ifndef OBSZARRYSOWANIA_H
#define OBSZARRYSOWANIA_H

#include <QWidget>
#include <QVector>

class ObszarRysowania : public QWidget
{
    Q_OBJECT
public:
    bool mRysowanie;
    QImage mRysunek;
    QColor mKolor;
    QString fileName;
    int * oldX = new int;
    int * oldY = new int;


    explicit ObszarRysowania(QWidget *parent = nullptr);
    ~ObszarRysowania();
    void mousePressEvent(QMouseEvent *zdarzenie);
    void mouseMoveEvent(QMouseEvent *zdarzenie);
    void mouseReleaseEvent(QMouseEvent *zdarzenie);
    void paintEvent(QPaintEvent *zdarzenie);
    void resizeEvent(QResizeEvent *zdarzenie);


signals:

public slots:
    void on_red_clicked();
    void on_blue_clicked();
    void on_yellow_clicked();
    void on_green_clicked();
    void on_erase_clicked();
    bool on_save_clicked();

};

#endif // OBSZARRYSOWANIA_H
