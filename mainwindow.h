#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"solarsystem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /**
     * @brief fitInView
     * Should be called when window resizes. Adjust graphics
     * scene to current window size so that it fits whole window
     * and keeps aspect ratio
     */
    void fitInView();

private slots:
    /**
     * @brief on_btnLaunch_clicked
     * Tells solar system to launch the rocket
     */
    void on_btnLaunch_clicked();

    /**
     * @brief on_sldTimeSpeed_valueChanged
     * Tells solar system to change time speed
     * @param value
     */
    void on_sldTimeSpeed_valueChanged(int value);

    /**
     * @brief on_sldGravityForce_valueChanged
     * Tells solar system to change gracity force
     * @param value
     */
    void on_sldGravityForce_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    SolarSystem* solarSystem;
    QGraphicsScene* scene;
    void resizeEvent(QResizeEvent * event);
};

#endif // MAINWINDOW_H
