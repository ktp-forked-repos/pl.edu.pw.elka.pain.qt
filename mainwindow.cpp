#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "solarsystem.h"
#include "solarsysteminitializer.h"
#include "constants.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    solarSystem = SolarSystemInitializer().getSolarSystem();
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(solarSystem->boundingRect());
    scene->addItem(solarSystem);
    ui->graphicsView->fitInView(solarSystem, Qt::KeepAspectRatio);
    QTimer* timer = new QTimer(ui->graphicsView);
    QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000 / 33);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLaunch_clicked()
{
    double v = ui->sldRocketVelocity->value();
    double angle = ui->sldRocketAngle->value();
    double vDefault = 50;
    solarSystem->launchRocket(v / vDefault, angle / 100 * PI * 2);
}

void MainWindow::on_sldTimeSpeed_valueChanged(int value)
{
    static const double defaultValue = 20;
    solarSystem->setTimeStep((double)value / defaultValue);
}

void MainWindow::on_sldGravityForce_valueChanged(int value)
{
    static const double defaultValue = 30;
    solarSystem->setGravity((double)value / defaultValue);
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
    QMainWindow::resizeEvent(event);
    fitInView();
}

void MainWindow::fitInView()
{
    ui->graphicsView->fitInView(solarSystem, Qt::KeepAspectRatio);
}
