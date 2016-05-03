#include "planet.h"
#include<math.h>
#include<QPainter>
#include"constants.h"

Planet::Planet(double radius, double mass, double distanceFromSun,
               double v, double angleToSun, QString name, QGraphicsItem *parent)
    : SolarObject(mass, parent), radius(radius), name(name)
{
    this->x = distanceFromSun * sin(angleToSun);
    this->y = distanceFromSun * cos(angleToSun);
    this->vx = v * cos(angleToSun);
    this->vy = v * -sin(angleToSun);
}


void Planet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE
{
    SolarObject::paint(painter, option, widget);
}
