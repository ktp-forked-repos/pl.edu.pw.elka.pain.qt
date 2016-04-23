#include "planet.h"
#include<math.h>

Planet::Planet(double radius, double mass, double distanceFromSun,
               double v, double angleToSun, QString name, QObject *parent)
    : SolarObject(mass, parent), radius(radius), name(name)
{
    this->x = distanceFromSun * cos(angleToSun);
    this-> y= distanceFromSun * sin(angleToSun);
    this->vx = v * cos(angleToSun);
    this->vy = v * sin(angleToSun);
}

