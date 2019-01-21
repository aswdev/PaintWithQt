#ifndef OBSZARRYSOWANIA_H
#define OBSZARRYSOWANIA_H

#include <QWidget>

class ObszarRysowania : public QWidget
{
    Q_OBJECT
public:
    explicit ObszarRysowania(QWidget *parent = nullptr);
    QString fileName;

signals:

public slots:
    void on_red_clicked();
    void on_blue_clicked();
    void on_yellow_clicked();
    void on_green_clicked();
    void on_erase_clicked();
    bool on_save_clicked(const QString &fileName);

};

#endif // OBSZARRYSOWANIA_H
