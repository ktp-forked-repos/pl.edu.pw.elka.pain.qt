#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_btnLaunch_clicked();

    void on_sldTimeSpeed_valueChanged(int value);

    void on_sldGravityForce_valueChanged(int value);

    void on_sldRocketVelocity_valueChanged(int value);

    void on_sldRocketAngle_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
