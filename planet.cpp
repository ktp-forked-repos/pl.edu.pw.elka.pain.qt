#include "planet.h"

Planet::Planet(unsigned int radius, unsigned int mass, unsigned int distanceFromSun,
               unsigned int v, unsigned int angleToSun, QObject *parent = 0)
    : SolarObject(mass, parent), radius(radius)
{

}

