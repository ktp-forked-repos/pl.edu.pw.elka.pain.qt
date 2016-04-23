#include "solarobject.h"

SolarObject::SolarObject(unsigned int mass, QObject *parent = 0): QObject(parent), mass(mass)
{

}

SolarObject::SolarObject(unsigned int mass, unsigned int x, unsigned int y,
                     unsigned int vx, unsigned int vy, QObject *parent = 0)
    : SolarObject(mass, parent), x(x), y(y), vx(vx), vy(vy)
{

}
