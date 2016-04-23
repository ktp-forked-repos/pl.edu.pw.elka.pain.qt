#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLaunch_clicked()
{
    throw "not implemented";
}

void MainWindow::on_sldTimeSpeed_valueChanged(int value)
{
    throw "not implemented";
}

void MainWindow::on_sldGravityForce_valueChanged(int value)
{
    throw "not implemented";
}

void MainWindow::on_sldRocketVelocity_valueChanged(int value)
{
    throw "not implemented";
}

void MainWindow::on_sldRocketAngle_valueChanged(int value)
{
    throw "not implemented";
}
