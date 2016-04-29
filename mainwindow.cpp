#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "solarsystem.h"
#include "solarsysteminitializer.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    solarSystem = SolarSystemInitializer().getSolarSystem();
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    scene->addItem(solarSystem);
    QRectF x = scene->sceneRect();
    ui->graphicsView->fitInView(QRectF(-200, -200, 400, 400), Qt::KeepAspectRatio);

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
    solarSystem->launchRocket(v, angle);
}
