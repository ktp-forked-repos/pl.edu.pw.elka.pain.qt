#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include <QObject>
#include "solarobject.h"
#include "planet.h"

class SolarSystem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit SolarSystem(QObject *parent = 0);
    /**
     * @brief solarObjects objects contained in this solar system
     */
    std::list<SolarObject*> solarObjects;
    /**
     * @brief GravityF Force of gravity described in m^3 / (kg * s^2)
     */
    double GravityF;
    /**
     * @brief timeStep amount of time used for single step of simulation described in seconds
     */
    double timeStep;
    /**
     * @brief activePlanet planet selected to launch rocket from
     */
    Planet* activePlanet;

    /**
     * @brief launchRocket method that launches the rocket from current active planet
     * @param v initial velocity of the rocket
     * @param angle angle from which rocket should be launched from planet
     */
    void launchRocket(double v, double angle);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    void advance(int step) Q_DECL_OVERRIDE;

signals:

public slots:
};

#endif // SOLARSYSTEM_H
