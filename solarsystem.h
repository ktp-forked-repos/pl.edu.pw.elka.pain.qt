#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include <QObject>
#include "solarobject.h"
#include "planet.h"

class SolarSystem : public QObject
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
    unsigned int GravityF;
    /**
     * @brief timeStep amount of time used for single step of simulation described in seconds
     */
    unsigned int timeStep;
    /**
     * @brief activePlanet planet selected to launch rocket from
     */
    Planet* activePlanet;

    /**
     * @brief step method used for moving all objects in system by one step
     */
    void step();

    /**
     * @brief launchRocket method that launches the rocket from current active planet
     * @param v initial velocity of the rocket
     * @param angle angle from which rocket should be launched from planet
     */
    void launchRocket(unsigned int v, unsigned int angle);
signals:

public slots:
};

#endif // SOLARSYSTEM_H
