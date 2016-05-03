#include "solarobject.h"
#include <QPainter>
#include<math.h>

SolarObject::SolarObject(double mass, QGraphicsItem *parent): QGraphicsItem(parent), mass(mass)
{

}

void SolarObject::advance(int step) Q_DECL_OVERRIDE
{
}

void SolarObject::changeVelocity(double dv, double angle)
{
    vx += sin(angle) * dv;
    vy += cos(angle) * dv;
}
