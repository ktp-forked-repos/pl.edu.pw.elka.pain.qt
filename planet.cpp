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

QRectF Planet::boundingRect() const Q_DECL_OVERRIDE
{
    return QRectF(-80, -80, 160, 160);
}

void Planet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE
{
    static QColor color(0, 0, 0);
    painter->setBrush(color);
    painter->drawEllipse(boundingRect());
}

QPainterPath Planet::shape() const Q_DECL_OVERRIDE
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}
