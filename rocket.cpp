#include "rocket.h"
#include <QtMath>

Rocket::Rocket(Planet* startPlanet, double v,
               double angle, QGraphicsItem *parent) : SolarObject(ROCKET_MASS, parent)
{
    x = startPlanet->x + startPlanet->radius * cos(angle);
    y = startPlanet->y + startPlanet->radius * sin(angle);
    vx = v * cos(angle);
    vy = v * sin(angle);
}

