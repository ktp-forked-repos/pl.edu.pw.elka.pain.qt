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
     * @brief GravityC Gravity constant described in m^3 / (kg * s^2)
     */
    double GravityC;
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

private:
    /**
     * @brief GravityCBase real gravity constant described in m^3 / (kg * s^2)
     */
    const double GravityCBase = 6.67408F;
    /**
     * @brief timeStepBase base amount of time used for single step of simulation in seconds
     */
    const double timeStepBase = 3600;

    void setObjectsPos();
    void setObjectsVelocity();
    std::list<std::pair<SolarObject*, SolarObject*> > getSolarObjectsPairs();

    /**
     * @brief getDistanceBetween calculates distance between objects
     * @param s1 first solar object
     * @param s2 second solar object
     * @return distance between two objects in kilometers
     * multipled by 10^6
     */
    double getDistanceBetween(SolarObject* s1, SolarObject* s2);

    /**
     * @brief getAngleBetween calculates relative angle between two
     * solar objects, assuming that first object is in the center
     * @param s1 first object relative to which angle is calculated
     * @param s2 second object
     * @return angle relative to first object in radians
     */
    double getAngleBetween(SolarObject* s1, SolarObject* s2);
};

#endif // SOLARSYSTEM_H
